#pragma once
// SWE-UNIT-0004 — 공통 데이터 타입 정의
// 참조: SWE3-UNIT-SPEC-0001 §3

#include <string>

// InputParser 파싱 결과 유형 (SWE3-UNIT-SPEC-0001 §3.1)
enum class InputType {
    OPERATION,  // 유효한 연산식 파싱 완료
    QUIT,       // q 또는 quit 종료 명령 입력
    INVALID     // 잘못된 형식 입력
};

// Calculator 연산 결과 반환 구조체 (SWE3-UNIT-SPEC-0001 §3.2, SWE-IF-0002)
struct OperationResult {
    bool        success;   // 연산 성공 여부 (0 나누기 시 false)
    double      result;    // 연산 결과값 (success=false 시 0.0)
    std::string errorMsg;  // 오류 메시지 (success=true 시 "")
};

// InputParser 파싱 결과 반환 구조체 (SWE3-UNIT-SPEC-0001 §3.3, SWE-IF-0003)
struct ParsedInput {
    InputType   type;      // 파싱 결과 유형
    double      operandA;  // 피연산자 A (type==OPERATION 시 유효)
    char        op;        // 연산자 (type==OPERATION 시 유효)
    double      operandB;  // 피연산자 B (type==OPERATION 시 유효)
    std::string errorMsg;  // 오류 메시지 (type==INVALID 시 유효)
};
