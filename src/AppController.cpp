// SWE-UNIT-0003 — AppController 클래스 구현
// 참조: SWE3-UNIT-SPEC-0001 §4.3.4 (내부 로직), §4.3.5 (출력 형식)

#include "AppController.h"

#include <iomanip>

// ── private 보조 함수 ──────────────────────────────────────────────────────

void AppController::printPrompt() {
    std::cout << "> " << std::flush;
}

void AppController::printResult(const OperationResult& res) {
    if (res.success) {
        // 정수로 딱 떨어지는 경우 소수점 불필요 표시 방지
        double val = res.result;
        if (val == static_cast<long long>(val)) {
            std::cout << "Result: " << static_cast<long long>(val) << "\n";
        } else {
            std::cout << "Result: " << val << "\n";
        }
    } else {
        std::cout << res.errorMsg << "\n";
    }
}

void AppController::printError(const std::string& msg) {
    std::cout << msg << "\n";
}

// ── public 함수 ───────────────────────────────────────────────────────────

int AppController::run() {
    std::string line;

    while (true) {
        printPrompt();

        if (!std::getline(std::cin, line)) {
            // EOF 또는 입력 오류 — 정상 종료 (SWE3-UNIT-SPEC-0001 §4.3.3)
            break;
        }

        ParsedInput parsed = inputParser.parse(line);

        switch (parsed.type) {
            case InputType::QUIT:
                return 0;

            case InputType::INVALID:
                printError(parsed.errorMsg);
                break;

            case InputType::OPERATION: {
                OperationResult res = calculator.calculate(
                    parsed.operandA, parsed.op, parsed.operandB);
                printResult(res);
                break;
            }
        }
    }

    return 0;
}
