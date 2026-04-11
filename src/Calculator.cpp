// SWE-UNIT-0001 — Calculator 클래스 구현
// 참조: SWE3-UNIT-SPEC-0001 §4.1.4 (내부 로직), §4.1.5 (판정 표)

#include "Calculator.h"

OperationResult Calculator::calculate(double a, char op, double b) {
    OperationResult res{false, 0.0, ""};

    switch (op) {
        case '+':
            res.success = true;
            res.result  = a + b;
            break;
        case '-':
            res.success = true;
            res.result  = a - b;
            break;
        case '*':
            res.success = true;
            res.result  = a * b;
            break;
        case '/':
            if (b == 0.0) {
                res.success  = false;
                res.errorMsg = "Error: Division by zero";
            } else {
                res.success = true;
                res.result  = a / b;
            }
            break;
        default:
            res.success  = false;
            res.errorMsg = std::string("Error: Unknown operator '") + op + "'";
            break;
    }

    return res;
}
