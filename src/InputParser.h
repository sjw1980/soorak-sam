#pragma once
// SWE-UNIT-0002 — InputParser 클래스 선언
// 참조: SWE3-UNIT-SPEC-0001 §4.2

#include <string>
#include "types.h"

class InputParser {
public:
    // 한 줄 문자열을 파싱하여 ParsedInput 반환 (SWE3-UNIT-SPEC-0001 §4.2.3)
    // 사전 조건: line은 임의의 문자열 (비어있어도 허용)
    // 사후 조건: QUIT / OPERATION / INVALID 중 하나 반환
    ParsedInput parse(const std::string& line);

private:
    // 앞뒤 공백 제거 (SWE3-UNIT-SPEC-0001 §4.2.3)
    std::string trim(const std::string& s);

    // 종료 명령 판별 — "q" 또는 "quit" (대소문자 무관) (SWE3-UNIT-SPEC-0001 §4.2.3)
    // 사전 조건: s는 trim 및 소문자 변환 완료 상태
    bool isQuitCommand(const std::string& s);
};
