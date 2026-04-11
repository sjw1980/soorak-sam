// SWE-TC-0009 ~ SWE-TC-0023 — InputParser 단위 테스트
// 참조: SWE3-UNIT-SPEC-0001 §4.2, SWE-UNIT-0002, SWE-REQ-0006~0010

#include <gtest/gtest.h>
#include "InputParser.h"

class InputParserTest : public ::testing::Test {
protected:
    InputParser parser;
};

// ─────────────────────────────────────────────
// SWE-TC-0009 — "q" → QUIT (SWE-REQ-0008)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0009_Quit_Lowercase_q) {
    ParsedInput res = parser.parse("q");
    EXPECT_EQ(res.type, InputType::QUIT);
}

// ─────────────────────────────────────────────
// SWE-TC-0010 — "Q" → QUIT 대소문자 무관 (SWE-REQ-0008)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0010_Quit_Uppercase_Q) {
    ParsedInput res = parser.parse("Q");
    EXPECT_EQ(res.type, InputType::QUIT);
}

// ─────────────────────────────────────────────
// SWE-TC-0011 — "quit" → QUIT (SWE-REQ-0008)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0011_Quit_Word_quit) {
    ParsedInput res = parser.parse("quit");
    EXPECT_EQ(res.type, InputType::QUIT);
}

// ─────────────────────────────────────────────
// SWE-TC-0012 — "QUIT" → QUIT 대소문자 무관 (SWE-REQ-0008)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0012_Quit_Word_QUIT) {
    ParsedInput res = parser.parse("QUIT");
    EXPECT_EQ(res.type, InputType::QUIT);
}

// ─────────────────────────────────────────────
// SWE-TC-0013 — 유효한 정수 덧셈 연산식 파싱 (SWE-REQ-0006)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0013_Operation_Addition) {
    ParsedInput res = parser.parse("3 + 5");
    EXPECT_EQ(res.type, InputType::OPERATION);
    EXPECT_DOUBLE_EQ(res.operandA, 3.0);
    EXPECT_EQ(res.op, '+');
    EXPECT_DOUBLE_EQ(res.operandB, 5.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0014 — 나누기 0 입력 파싱 (SWE-REQ-0005, OPERATION 반환 — Calculator에서 처리)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0014_Operation_DivisionByZero_Parsed) {
    ParsedInput res = parser.parse("10 / 0");
    EXPECT_EQ(res.type, InputType::OPERATION);
    EXPECT_DOUBLE_EQ(res.operandA, 10.0);
    EXPECT_EQ(res.op, '/');
    EXPECT_DOUBLE_EQ(res.operandB, 0.0);
}

// ─────────────────────────────────────────────
// SWE-TC-0015 — 빈 입력 → INVALID (SWE-REQ-0007)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0015_Invalid_EmptyInput) {
    ParsedInput res = parser.parse("");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0016 — 문자열만 입력 → INVALID (SWE-REQ-0007)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0016_Invalid_TextInput) {
    ParsedInput res = parser.parse("abc");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0017 — 알 수 없는 연산자 → INVALID (SWE-REQ-0009)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0017_Invalid_UnknownOperator) {
    ParsedInput res = parser.parse("3 % 5");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0018 — 토큰 초과 입력 → INVALID (SWE-REQ-0007)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0018_Invalid_TooManyTokens) {
    ParsedInput res = parser.parse("1 + 2 3");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0019 — 앞뒤 공백 입력 → OPERATION 정상 파싱 (SWE-REQ-0006, 경계값)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0019_Operation_LeadingTrailingSpaces) {
    ParsedInput res = parser.parse("  3 + 5  ");
    EXPECT_EQ(res.type, InputType::OPERATION);
    EXPECT_DOUBLE_EQ(res.operandA, 3.0);
    EXPECT_EQ(res.op, '+');
    EXPECT_DOUBLE_EQ(res.operandB, 5.0);
}

// ─────────────────────────────────────────────
// SWE-TC-0020 — 소수 피연산자 파싱 (SWE-REQ-0006, 경계값)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0020_Operation_FloatingPoint) {
    ParsedInput res = parser.parse("3.14 * 2.0");
    EXPECT_EQ(res.type, InputType::OPERATION);
    EXPECT_DOUBLE_EQ(res.operandA, 3.14);
    EXPECT_EQ(res.op, '*');
    EXPECT_DOUBLE_EQ(res.operandB, 2.0);
}

// ─────────────────────────────────────────────
// SWE-TC-0021 — 음수 피연산자 파싱 (SWE-REQ-0006, 경계값)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0021_Operation_NegativeOperand) {
    ParsedInput res = parser.parse("-5 + 3");
    EXPECT_EQ(res.type, InputType::OPERATION);
    EXPECT_DOUBLE_EQ(res.operandA, -5.0);
    EXPECT_EQ(res.op, '+');
    EXPECT_DOUBLE_EQ(res.operandB, 3.0);
}

// ─────────────────────────────────────────────
// SWE-TC-0022 — 숫자만 입력 (연산자 없음) → INVALID (SWE-REQ-0007)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0022_Invalid_NumberOnly) {
    ParsedInput res = parser.parse("42");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0023 — 공백만 입력 → INVALID (SWE-REQ-0007, 경계값)
// ─────────────────────────────────────────────
TEST_F(InputParserTest, TC0023_Invalid_WhitespaceOnly) {
    ParsedInput res = parser.parse("   ");
    EXPECT_EQ(res.type, InputType::INVALID);
    EXPECT_NE(res.errorMsg, "");
}
