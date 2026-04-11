// SWE-UNIT-0002 — InputParser 클래스 구현
// 참조: SWE3-UNIT-SPEC-0001 §4.2.4 (내부 로직), §4.2.5 (판정 표)

#include "InputParser.h"

#include <algorithm>
#include <cctype>
#include <sstream>

// ── private 보조 함수 ──────────────────────────────────────────────────────

std::string InputParser::trim(const std::string& s) {
    const std::string whitespace = " \t\r\n";
    const auto begin = s.find_first_not_of(whitespace);
    if (begin == std::string::npos) {
        return "";
    }
    const auto end = s.find_last_not_of(whitespace);
    return s.substr(begin, end - begin + 1);
}

bool InputParser::isQuitCommand(const std::string& s) {
    return (s == "q" || s == "quit");
}

// ── public 함수 ───────────────────────────────────────────────────────────

ParsedInput InputParser::parse(const std::string& line) {
    std::string trimmed = trim(line);

    // 소문자 변환 (종료 명령 대소문자 무관 판별용)
    std::string lower = trimmed;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    // 종료 명령 판별 (SWE3-UNIT-SPEC-0001 §4.2.4)
    if (isQuitCommand(lower)) {
        return ParsedInput{InputType::QUIT, 0.0, '\0', 0.0, ""};
    }

    // 연산식 파싱 (SWE3-UNIT-SPEC-0001 §4.2.4)
    std::istringstream stream(trimmed);
    double a = 0.0, b = 0.0;
    char   op = '\0';
    std::string extra;

    if (!(stream >> a >> op >> b)) {
        return ParsedInput{InputType::INVALID, 0.0, '\0', 0.0,
                           "Error: Invalid input format. Use: <number> <operator> <number>"};
    }

    // 토큰 초과 검사
    if (stream >> extra) {
        return ParsedInput{InputType::INVALID, 0.0, '\0', 0.0,
                           "Error: Too many tokens in input"};
    }

    // 연산자 유효성 검사
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        return ParsedInput{InputType::INVALID, 0.0, '\0', 0.0,
                           std::string("Error: Unknown operator '") + op + "'. Use +, -, *, /"};
    }

    return ParsedInput{InputType::OPERATION, a, op, b, ""};
}
