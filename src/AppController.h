#pragma once
// SWE-UNIT-0003 — AppController 클래스 선언
// 참조: SWE3-UNIT-SPEC-0001 §4.3

#include <iostream>
#include "Calculator.h"
#include "InputParser.h"
#include "types.h"

class AppController {
public:
    // 프로그램 메인 루프 실행 (SWE3-UNIT-SPEC-0001 §4.3.3)
    // 사전 조건: stdin이 열려 있음
    // 사후 조건: QUIT 명령 또는 EOF 발생 시 0 반환
    int run();

private:
    Calculator  calculator;
    InputParser inputParser;

    // 연산 결과 출력 — 성공: "Result: <value>", 실패: errorMsg (SWE3-UNIT-SPEC-0001 §4.3.5)
    void printResult(const OperationResult& res);

    // 파싱 오류 메시지 출력 (SWE3-UNIT-SPEC-0001 §4.3.5)
    void printError(const std::string& msg);

    // 입력 프롬프트("> ") 출력 (SWE3-UNIT-SPEC-0001 §4.3.5)
    void printPrompt();
};
