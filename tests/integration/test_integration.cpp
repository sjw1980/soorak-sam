// SWE-ITC-0001 ~ SWE-ITC-0013 — AppController 통합 테스트 (End-to-End)
// 참조: SWE5-ITC-SPEC-0001, SWE2-ARCH-0001 (SWE-IF-0001~0003)
// 대상 인터페이스: SWE-IF-0001 (AppController→Calculator), SWE-IF-0002 (Calculator→AppController),
//               SWE-IF-0003 (InputParser→AppController)
// 통합 전략: 점진적 통합 — AppController + InputParser + Calculator E2E 검증
// 검증 방법: std::cin / std::cout 버퍼 리다이렉션으로 stdin/stdout 시뮬레이션

#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "AppController.h"

// ─────────────────────────────────────────────────────────────────────────────
// 통합 테스트 픽스처
// stdin → std::istringstream, stdout → std::ostringstream 으로 리다이렉션
// ─────────────────────────────────────────────────────────────────────────────
struct AppResult {
    std::string output;
    int         exitCode;
};

class IntegrationTest : public ::testing::Test {
protected:
    // 주어진 입력으로 AppController 실행 — 표준 출력 및 종료 코드 반환
    AppResult runApp(const std::string& input) {
        std::istringstream fakeIn(input);
        std::ostringstream fakeOut;

        std::streambuf* origIn  = std::cin.rdbuf(fakeIn.rdbuf());
        std::streambuf* origOut = std::cout.rdbuf(fakeOut.rdbuf());

        AppController app;
        int exitCode = app.run();

        std::cin.rdbuf(origIn);
        std::cout.rdbuf(origOut);

        return AppResult{fakeOut.str(), exitCode};
    }
};

// ─────────────────────────────────────────────────────────────────────────────
// 3.1 SWE-IF-0001/0002 — AppController ↔ Calculator 인터페이스 검증
// ─────────────────────────────────────────────────────────────────────────────

// SWE-ITC-0001 — 덧셈 연산 End-to-End (SWE-REQ-0001)
TEST_F(IntegrationTest, ITC0001_Addition_E2E) {
    auto r = runApp("3 + 5\nq\n");
    EXPECT_EQ(r.output, "> Result: 8\n> ");
}

// SWE-ITC-0002 — 뺄셈 연산 End-to-End (SWE-REQ-0002)
TEST_F(IntegrationTest, ITC0002_Subtraction_E2E) {
    auto r = runApp("10 - 3\nq\n");
    EXPECT_EQ(r.output, "> Result: 7\n> ");
}

// SWE-ITC-0003 — 곱셈 연산 End-to-End (SWE-REQ-0003)
TEST_F(IntegrationTest, ITC0003_Multiplication_E2E) {
    auto r = runApp("4 * 3\nq\n");
    EXPECT_EQ(r.output, "> Result: 12\n> ");
}

// SWE-ITC-0004 — 나눗셈 연산 End-to-End (SWE-REQ-0004)
TEST_F(IntegrationTest, ITC0004_Division_E2E) {
    auto r = runApp("10 / 2\nq\n");
    EXPECT_EQ(r.output, "> Result: 5\n> ");
}

// SWE-ITC-0005 — 0 나누기 오류 End-to-End (SWE-REQ-0005)
TEST_F(IntegrationTest, ITC0005_DivisionByZero_E2E) {
    auto r = runApp("7 / 0\nq\n");
    EXPECT_EQ(r.output, "> Error: Division by zero\n> ");
}

// SWE-ITC-0006 — 소수 연산 End-to-End — 1.5 * 2.0 = 3 (정수형 출력 검증, SWE-REQ-0003)
TEST_F(IntegrationTest, ITC0006_FloatingPoint_E2E) {
    auto r = runApp("1.5 * 2.0\nq\n");
    EXPECT_EQ(r.output, "> Result: 3\n> ");
}

// SWE-ITC-0007 — 음수 피연산자 End-to-End — -3 + -5 = -8 (SWE-REQ-0001)
TEST_F(IntegrationTest, ITC0007_NegativeOperands_E2E) {
    auto r = runApp("-3 + -5\nq\n");
    EXPECT_EQ(r.output, "> Result: -8\n> ");
}

// ─────────────────────────────────────────────────────────────────────────────
// 3.2 SWE-IF-0003 — AppController ↔ InputParser 인터페이스 검증
// ─────────────────────────────────────────────────────────────────────────────

// SWE-ITC-0008 — "q" 입력 → 정상 종료 (exit code 0, SWE-REQ-0008)
TEST_F(IntegrationTest, ITC0008_Quit_q_E2E) {
    auto r = runApp("q\n");
    EXPECT_EQ(r.output, "> ");
    EXPECT_EQ(r.exitCode, 0);
}

// SWE-ITC-0009 — "quit" 입력 → 정상 종료 (exit code 0, SWE-REQ-0008)
TEST_F(IntegrationTest, ITC0009_Quit_quit_E2E) {
    auto r = runApp("quit\n");
    EXPECT_EQ(r.output, "> ");
    EXPECT_EQ(r.exitCode, 0);
}

// SWE-ITC-0010 — 잘못된 입력 → 오류 메시지 출력 후 루프 계속 (SWE-REQ-0007)
TEST_F(IntegrationTest, ITC0010_InvalidTextInput_E2E) {
    auto r = runApp("abc\nq\n");
    // 오류 메시지 포함 확인
    EXPECT_NE(r.output.find("Error:"), std::string::npos);
    // 오류 후에도 프롬프트가 다시 출력되어 루프 계속됨 확인 (두 번째 "> " 존재)
    size_t second_prompt = r.output.find("> ", 2);
    EXPECT_NE(second_prompt, std::string::npos);
}

// SWE-ITC-0011 — 빈 입력 → 오류 메시지 출력 후 루프 계속 (SWE-REQ-0007)
TEST_F(IntegrationTest, ITC0011_EmptyInput_E2E) {
    auto r = runApp("\nq\n");
    EXPECT_NE(r.output.find("Error:"), std::string::npos);
}

// SWE-ITC-0012 — 알 수 없는 연산자(%) → 오류 메시지 출력 (SWE-REQ-0009)
TEST_F(IntegrationTest, ITC0012_UnknownOperator_E2E) {
    auto r = runApp("3 % 5\nq\n");
    EXPECT_NE(r.output.find("Error:"), std::string::npos);
}

// ─────────────────────────────────────────────────────────────────────────────
// 3.3 복합 시나리오 — 다중 연산 반복 루프
// ─────────────────────────────────────────────────────────────────────────────

// SWE-ITC-0013 — 다중 연산 후 종료 (SWE-REQ-0007, SWE-REQ-0010)
// 3+5=8, 10/2=5 순서로 두 연산을 반복한 후 q로 종료
TEST_F(IntegrationTest, ITC0013_MultipleOps_E2E) {
    auto r = runApp("3 + 5\n10 / 2\nq\n");
    EXPECT_EQ(r.output, "> Result: 8\n> Result: 5\n> ");
}
