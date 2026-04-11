#pragma once
// SWE-UNIT-0001 — Calculator 클래스 선언
// 참조: SWE3-UNIT-SPEC-0001 §4.1

#include "types.h"

class Calculator {
public:
    // 두 피연산자와 연산자를 받아 4칙 연산 수행 (SWE3-UNIT-SPEC-0001 §4.1.3)
    // 사전 조건: op ∈ {'+', '-', '*', '/'}
    // 사후 조건: success=true → result=a op b, errorMsg=""
    //           op=='/' && b==0.0 → success=false, errorMsg="Error: Division by zero"
    OperationResult calculate(double a, char op, double b);
};
