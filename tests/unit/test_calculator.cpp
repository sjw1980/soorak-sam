// SWE-TC-0001 ~ SWE-TC-0008 — Calculator 단위 테스트
// 참조: SWE3-UNIT-SPEC-0001 §4.1, SWE-UNIT-0001, SWE-REQ-0001~0005,0009,0010

#include <gtest/gtest.h>
#include "Calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

// ─────────────────────────────────────────────
// SWE-TC-0001 — 덧셈 정상 동작 (SWE-REQ-0001)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0001_Addition_Normal) {
    OperationResult res = calc.calculate(3.0, '+', 5.0);
    EXPECT_TRUE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 8.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0002 — 뺄셈 정상 동작 (SWE-REQ-0002)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0002_Subtraction_Normal) {
    OperationResult res = calc.calculate(10.0, '-', 3.0);
    EXPECT_TRUE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 7.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0003 — 곱셈 정상 동작 (SWE-REQ-0003)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0003_Multiplication_Normal) {
    OperationResult res = calc.calculate(4.0, '*', 3.0);
    EXPECT_TRUE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 12.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0004 — 나눗셈 정상 동작 (SWE-REQ-0004)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0004_Division_Normal) {
    OperationResult res = calc.calculate(10.0, '/', 2.0);
    EXPECT_TRUE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 5.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0005 — 0 나누기 예외 처리 (SWE-REQ-0005)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0005_Division_ByZero) {
    OperationResult res = calc.calculate(7.0, '/', 0.0);
    EXPECT_FALSE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 0.0);
    EXPECT_EQ(res.errorMsg, "Error: Division by zero");
}

// ─────────────────────────────────────────────
// SWE-TC-0006 — 음수 피연산자 정상 동작 (SWE-REQ-0001, 경계값)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0006_Negative_Operands) {
    OperationResult res = calc.calculate(-3.0, '+', -5.0);
    EXPECT_TRUE(res.success);
    EXPECT_DOUBLE_EQ(res.result, -8.0);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0007 — 소수 피연산자 정상 동작 (SWE-REQ-0004, 경계값)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0007_Floating_Point) {
    OperationResult res = calc.calculate(1.0, '/', 3.0);
    EXPECT_TRUE(res.success);
    EXPECT_NEAR(res.result, 0.3333333333333333, 1e-9);
    EXPECT_EQ(res.errorMsg, "");
}

// ─────────────────────────────────────────────
// SWE-TC-0008 — 알 수 없는 연산자 (SWE-REQ-0009, 예외)
// ─────────────────────────────────────────────
TEST_F(CalculatorTest, TC0008_UnknownOperator) {
    OperationResult res = calc.calculate(3.0, '%', 5.0);
    EXPECT_FALSE(res.success);
    EXPECT_DOUBLE_EQ(res.result, 0.0);
    EXPECT_NE(res.errorMsg, "");
}
