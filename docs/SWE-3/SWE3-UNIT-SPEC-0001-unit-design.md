# SWE-3 소프트웨어 단위 상세 설계 명세서

| 항목 | 내용 |
|------|------|
| 문서 ID | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-3 전문가 |
| 승인자 | — |
| 참조 문서 | [SWE1-REQ-SPEC-0001](../SWE-1/SWE-1-requirements.md) (SWE-1 요구사항 명세서), [SWE2-ARCH-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md) (SWE-2 아키텍처 설계서) |

---

## 1. 개요

### 1.1 목적

본 문서는 CLI 계산기 소프트웨어의 소프트웨어 단위(Unit) 상세 설계를 정의한다.
SWE-2에서 도출된 컴포넌트([SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001)~[SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003))를 단위로 분해하고,
각 단위의 함수/클래스 인터페이스, 사전/사후 조건, 내부 로직 알고리즘을 명세하여
SWE-4 단위 테스트의 기반을 제공한다.

### 1.2 범위

- 대상 소프트웨어: CLI 계산기 (`calculator`)
- 구현 언어: C++17
- 상위 문서: [SWE2-ARCH-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md)

### 1.3 설계 원칙

- **단일 책임 원칙(SRP)**: 각 단위는 하나의 명확한 책임만 가진다.
- **인터페이스 분리**: 단위 간 통신은 선언된 함수 시그니처를 통해서만 이루어진다.
- **테스트 용이성**: 모든 단위는 외부 의존 없이 독립적으로 단위 테스트 가능해야 한다.
- **C++17 준수**: 모든 코드는 `-std=c++17` 플래그로 빌드 가능해야 한다.

---

## 2. 단위 목록

| ID | 단위명 | 상위 컴포넌트 ID | 역할 요약 | 구현 파일 | 버전 | 날짜 | 상태 |
|----|--------|----------------|---------|---------|------|------|------|
| [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | Calculator | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | 두 피연산자와 연산자를 받아 4칙 연산 수행 및 0 나누기 예외 처리 | `Calculator.h` / `Calculator.cpp` | v1.0 | 2026-04-11 | Draft |
| [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) | InputParser | [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) | 표준 입력 문자열을 파싱하여 연산 요청·종료 명령·오류를 구분 반환 | `InputParser.h` / `InputParser.cpp` | v1.0 | 2026-04-11 | Draft |
| [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | AppController | [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) | 프로그램 메인 루프 관리, InputParser·Calculator 조율, 결과/오류 출력 | `AppController.h` / `AppController.cpp` | v1.0 | 2026-04-11 | Draft |
| [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) | Types (공통 타입) | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001), [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) | 공통 데이터 구조체(OperationResult, ParsedInput)·열거형(InputType) 정의 | `types.h` | v1.0 | 2026-04-11 | Draft |

---

<a id="SWE-UNIT-0004"></a>
## 3. 공통 데이터 타입 정의 ([SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004))

### 3.1 열거형: `InputType`

| 항목 | 내용 |
|------|------|
| 단위 ID | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) |
| 파일 | `types.h` |
| 설명 | InputParser의 파싱 결과 유형을 구분하는 열거형 |

```cpp
enum class InputType {
    OPERATION,  // 유효한 연산식 파싱 완료
    QUIT,       // q 또는 quit 종료 명령 입력
    INVALID     // 잘못된 형식 입력
};
```

### 3.2 구조체: `OperationResult`

| 항목 | 내용 |
|------|------|
| 단위 ID | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) |
| 파일 | `types.h` |
| 설명 | Calculator의 연산 결과 반환 구조체 ([SWE-IF-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0002) 구현) |

```cpp
struct OperationResult {
    bool        success;   // 연산 성공 여부 (0 나누기 시 false)
    double      result;    // 연산 결과값 (success=false 시 0.0)
    std::string errorMsg;  // 오류 메시지 (success=true 시 빈 문자열)
};
```

| 필드 | 타입 | 설명 | 유효 범위 |
|------|------|------|---------|
| `success` | `bool` | 연산 성공 여부 | `true` / `false` |
| `result` | `double` | 연산 결과 | 임의의 실수 (success=false 시 0.0) |
| `errorMsg` | `std::string` | 오류 메시지 | success=true 시 `""`, 0나누기 시 `"Error: Division by zero"` |

### 3.3 구조체: `ParsedInput`

| 항목 | 내용 |
|------|------|
| 단위 ID | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) |
| 파일 | `types.h` |
| 설명 | InputParser의 파싱 결과 반환 구조체 ([SWE-IF-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0003) 구현) |

```cpp
struct ParsedInput {
    InputType   type;      // 파싱 결과 유형
    double      operandA;  // 피연산자 A (type==OPERATION 시 유효)
    char        op;        // 연산자 (type==OPERATION 시 유효)
    double      operandB;  // 피연산자 B (type==OPERATION 시 유효)
    std::string errorMsg;  // 오류 메시지 (type==INVALID 시 유효)
};
```

| 필드 | 타입 | 설명 | 유효 범위 |
|------|------|------|---------|
| `type` | `InputType` | 파싱 결과 유형 | `OPERATION` / `QUIT` / `INVALID` |
| `operandA` | `double` | 첫 번째 피연산자 | 임의의 실수 (type==OPERATION 시만 유효) |
| `op` | `char` | 연산자 문자 | `'+'`, `'-'`, `'*'`, `'/'` (type==OPERATION 시만 유효) |
| `operandB` | `double` | 두 번째 피연산자 | 임의의 실수 (type==OPERATION 시만 유효) |
| `errorMsg` | `std::string` | 오류 메시지 | type==INVALID 시 오류 내용, 그 외 `""` |

---

## 4. 단위 상세 설계

<a id="SWE-UNIT-0001"></a>
### 4.1 [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) — Calculator

#### 4.1.1 기본 정보

| 항목 | 내용 |
|------|------|
| ID | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) |
| 단위명 | Calculator |
| 상위 컴포넌트 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) |
| 구현 파일 | `Calculator.h`, `Calculator.cpp` |
| 관련 요구사항 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001), [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002), [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003), [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004), [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005), [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009), [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) |
| 소비 인터페이스 | [SWE-IF-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0001) (OperationRequest: operandA, op, operandB 수신) |
| 제공 인터페이스 | [SWE-IF-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0002) (OperationResult 반환) |

#### 4.1.2 클래스 선언

```cpp
// Calculator.h
#pragma once
#include "types.h"

class Calculator {
public:
    OperationResult calculate(double a, char op, double b);
};
```

#### 4.1.3 함수 인터페이스 명세

| 항목 | 내용 |
|------|------|
| 함수명 | `calculate` |
| 시그니처 | `OperationResult calculate(double a, char op, double b)` |
| 입력 파라미터 | `a: double` — 피연산자 A |
| | `op: char` — 연산자 (`'+'`, `'-'`, `'*'`, `'/'` 중 하나) |
| | `b: double` — 피연산자 B |
| 출력/반환 | `OperationResult` — 연산 결과 구조체 |
| 사전 조건 | `op` ∈ `{'+', '-', '*', '/'}` (InputParser에 의해 검증 완료) |
| 사후 조건 (성공) | `success = true`, `result = a op b`, `errorMsg = ""` |
| 사후 조건 (0 나누기) | `op == '/'` && `b == 0.0` → `success = false`, `result = 0.0`, `errorMsg = "Error: Division by zero"` |
| 예외 | 없음 — 모든 오류는 OperationResult.success를 통해 반환 |

#### 4.1.4 내부 로직 (알고리즘)

```
function calculate(a, op, b):
  result ← OperationResult{false, 0.0, ""}
  switch op:
    case '+':
      result.success ← true
      result.result  ← a + b
    case '-':
      result.success ← true
      result.result  ← a - b
    case '*':
      result.success ← true
      result.result  ← a * b
    case '/':
      if b == 0.0:
        result.success  ← false
        result.errorMsg ← "Error: Division by zero"
      else:
        result.success ← true
        result.result  ← a / b
    default:
      result.success  ← false
      result.errorMsg ← "Error: Unknown operator"
  return result
```

#### 4.1.5 판정 표 (Decision Table)

| op | b | 결과 success | 결과 result | 결과 errorMsg |
|----|---|-------------|------------|--------------|
| `'+'` | 임의 | `true` | `a + b` | `""` |
| `'-'` | 임의 | `true` | `a - b` | `""` |
| `'*'` | 임의 | `true` | `a * b` | `""` |
| `'/'` | ≠ 0 | `true` | `a / b` | `""` |
| `'/'` | = 0 | `false` | `0.0` | `"Error: Division by zero"` |

---

<a id="SWE-UNIT-0002"></a>
### 4.2 [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) — InputParser

#### 4.2.1 기본 정보

| 항목 | 내용 |
|------|------|
| ID | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) |
| 단위명 | InputParser |
| 상위 컴포넌트 | [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) |
| 구현 파일 | `InputParser.h`, `InputParser.cpp` |
| 관련 요구사항 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006), [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007), [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008), [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009), [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) |
| 소비 인터페이스 | 없음 (stdin 직접 읽기는 AppController에서 수행; parse()에 문자열 전달) |
| 제공 인터페이스 | [SWE-IF-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0003) (ParsedInput 반환) |

#### 4.2.2 클래스 선언

```cpp
// InputParser.h
#pragma once
#include <string>
#include "types.h"

class InputParser {
public:
    ParsedInput parse(const std::string& line);

private:
    std::string trim(const std::string& s);
    bool        isQuitCommand(const std::string& s);
};
```

#### 4.2.3 함수 인터페이스 명세

**`parse()` — 공개(public) 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `parse` |
| 시그니처 | `ParsedInput parse(const std::string& line)` |
| 입력 파라미터 | `line: const std::string&` — 사용자가 입력한 한 줄의 문자열 (개행 포함 가능) |
| 출력/반환 | `ParsedInput` — 파싱 결과 구조체 |
| 사전 조건 | `line`은 임의의 문자열 (비어있어도 허용) |
| 사후 조건 (QUIT) | `line`이 `"q"` 또는 `"quit"` (대소문자 무시)이면 `type = QUIT` 반환 |
| 사후 조건 (OPERATION) | `line`이 `<double> <char> <double>` 형식이고 op∈{+,-,*,/}이면 `type = OPERATION` 반환 |
| 사후 조건 (INVALID) | 그 외 모든 경우 `type = INVALID`, `errorMsg`에 원인 포함하여 반환 |
| 예외 | 없음 — 모든 오류는 ParsedInput.type을 통해 반환 |

**`trim()` — 비공개(private) 보조 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `trim` |
| 시그니처 | `std::string trim(const std::string& s)` |
| 설명 | 입력 문자열의 앞뒤 공백(스페이스, 탭, 개행) 제거 후 반환 |
| 입력 | `s: const std::string&` |
| 출력 | 앞뒤 공백이 제거된 `std::string` |
| 사전 조건 | 없음 |
| 사후 조건 | 반환값의 첫/마지막 문자는 공백 문자가 아님 (또는 빈 문자열) |

**`isQuitCommand()` — 비공개(private) 보조 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `isQuitCommand` |
| 시그니처 | `bool isQuitCommand(const std::string& s)` |
| 설명 | 문자열이 종료 명령(`"q"` 또는 `"quit"`, 대소문자 무관)인지 판별 |
| 입력 | `s: const std::string&` (trim 적용 완료된 소문자 문자열) |
| 출력 | `true` = 종료 명령, `false` = 아님 |
| 사전 조건 | `s`는 trim 및 소문자 변환이 적용된 상태 |
| 사후 조건 | `s == "q"` 또는 `s == "quit"` 시 `true` 반환 |

#### 4.2.4 내부 로직 (알고리즘)

```
function parse(line):
  trimmed ← trim(line)
  lower   ← toLower(trimmed)

  // 종료 명령 판별
  if isQuitCommand(lower):
    return ParsedInput{QUIT, 0.0, '\0', 0.0, ""}

  // 연산식 파싱 (istringstream 활용)
  stream ← istringstream(trimmed)
  a      ← double
  op     ← char
  b      ← double
  extra  ← string

  if NOT (stream >> a >> op >> b):
    return ParsedInput{INVALID, 0.0, '\0', 0.0, "Error: Invalid input format. Use: <number> <operator> <number>"}

  if stream >> extra:
    return ParsedInput{INVALID, 0.0, '\0', 0.0, "Error: Too many tokens in input"}

  // 연산자 유효성 검사
  if op NOT IN {'+', '-', '*', '/'}:
    return ParsedInput{INVALID, 0.0, '\0', 0.0, "Error: Unknown operator '" + op + "'. Use +, -, *, /"}

  return ParsedInput{OPERATION, a, op, b, ""}
```

#### 4.2.5 판정 표 (Decision Table)

| 입력 예시 | trim 결과 | isQuitCommand | 파싱 성공 | op 유효 | 반환 type | 비고 |
|---------|---------|--------------|---------|--------|---------|------|
| `"q"` | `"q"` | true | — | — | `QUIT` | |
| `"Q"` | `"Q"` | true | — | — | `QUIT` | 대소문자 무관 |
| `"quit"` | `"quit"` | true | — | — | `QUIT` | |
| `"3.0 + 5.0"` | `"3.0 + 5.0"` | false | true | true | `OPERATION` | a=3.0, op='+', b=5.0 |
| `"10 / 0"` | `"10 / 0"` | false | true | true | `OPERATION` | a=10, op='/', b=0 (Calculator에서 예외 처리) |
| `"abc"` | `"abc"` | false | false | — | `INVALID` | 형식 오류 |
| `"3 % 5"` | `"3 % 5"` | false | true | false | `INVALID` | 연산자 오류 |
| `""` | `""` | false | false | — | `INVALID` | 빈 입력 |
| `"1 + 2 3"` | `"1 + 2 3"` | false | true (but extra) | — | `INVALID` | 토큰 초과 |

---

<a id="SWE-UNIT-0003"></a>
### 4.3 [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) — AppController

#### 4.3.1 기본 정보

| 항목 | 내용 |
|------|------|
| ID | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) |
| 단위명 | AppController |
| 상위 컴포넌트 | [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) |
| 구현 파일 | `AppController.h`, `AppController.cpp` |
| 관련 요구사항 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006), [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007), [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008), [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) |
| 소비 인터페이스 | [SWE-IF-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0001) (OperationRequest: Calculator.calculate() 호출 파라미터 공급) |
| | [SWE-IF-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0002) (OperationResult: Calculator.calculate() 반환값 수신) |
| | [SWE-IF-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0003) (ParsedInput: InputParser.parse() 반환값 수신) |
| 제공 인터페이스 | 없음 (최상위 컨트롤러) |

#### 4.3.2 클래스 선언

```cpp
// AppController.h
#pragma once
#include <iostream>
#include "Calculator.h"
#include "InputParser.h"
#include "types.h"

class AppController {
public:
    int run();

private:
    Calculator  calculator;
    InputParser inputParser;

    void printResult(const OperationResult& res);
    void printError(const std::string& msg);
    void printPrompt();
};
```

#### 4.3.3 함수 인터페이스 명세

**`run()` — 공개(public) 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `run` |
| 시그니처 | `int run()` |
| 입력 파라미터 | 없음 (stdin으로부터 간접 입력) |
| 출력/반환 | `int` — 프로그램 종료 코드 (정상 종료 시 `0`) |
| 사전 조건 | 프로그램이 정상 시작되었으며 stdin이 열려 있음 |
| 사후 조건 | 종료 명령(`q`/`quit`) 수신 또는 EOF 발생 시 `0` 반환 |
| 예외 | 없음 — 내부 오류는 stderr 또는 stdout으로 출력 후 루프 유지 |

**`printResult()` — 비공개(private) 보조 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `printResult` |
| 시그니처 | `void printResult(const OperationResult& res)` |
| 설명 | 연산 성공 시 `"Result: <value>"`, 실패 시 `res.errorMsg`를 stdout에 출력 |
| 사전 조건 | `res`는 Calculator::calculate()의 유효한 반환값 |
| 사후 조건 | stdout에 결과 또는 오류 메시지가 출력됨 |

**`printError()` — 비공개(private) 보조 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `printError` |
| 시그니처 | `void printError(const std::string& msg)` |
| 설명 | 파싱 오류 메시지를 stdout에 출력 |
| 사전 조건 | `msg`는 비어있지 않은 오류 메시지 문자열 |
| 사후 조건 | stdout에 오류 메시지가 출력됨 |

**`printPrompt()` — 비공개(private) 보조 함수**

| 항목 | 내용 |
|------|------|
| 함수명 | `printPrompt` |
| 시그니처 | `void printPrompt()` |
| 설명 | 입력 프롬프트(`"> "`)를 stdout에 출력 |
| 사전 조건 | 없음 |
| 사후 조건 | stdout에 프롬프트 문자열 출력됨 |

#### 4.3.4 내부 로직 (알고리즘)

```
function run():
  while true:
    printPrompt()
    line ← string
    if NOT getline(stdin, line):   // EOF 또는 입력 오류 시
      break

    parsed ← inputParser.parse(line)

    switch parsed.type:
      case QUIT:
        return 0

      case INVALID:
        printError(parsed.errorMsg)
        continue

      case OPERATION:
        res ← calculator.calculate(parsed.operandA, parsed.op, parsed.operandB)
        printResult(res)
        continue

  return 0
```

#### 4.3.5 출력 형식 명세

| 상황 | 출력 예시 |
|------|---------|
| 정상 연산 결과 | `Result: 8` |
| 0 나누기 오류 | `Error: Division by zero` |
| 잘못된 입력 형식 | `Error: Invalid input format. Use: <number> <operator> <number>` |
| 알 수 없는 연산자 | `Error: Unknown operator '%'. Use +, -, *, /` |
| 입력 프롬프트 | `> ` |

---

## 5. 파일 구조

```
src/
├── main.cpp          # main() 함수 — AppController 인스턴스 생성 후 run() 호출
├── types.h           # SWE-UNIT-0004 — 공통 데이터 타입 정의
├── Calculator.h      # SWE-UNIT-0001 — Calculator 클래스 선언
├── Calculator.cpp    # SWE-UNIT-0001 — Calculator 클래스 구현
├── InputParser.h     # SWE-UNIT-0002 — InputParser 클래스 선언
├── InputParser.cpp   # SWE-UNIT-0002 — InputParser 클래스 구현
├── AppController.h   # SWE-UNIT-0003 — AppController 클래스 선언
└── AppController.cpp # SWE-UNIT-0003 — AppController 클래스 구현
```

`main.cpp` 진입점 구조:
```cpp
// main.cpp
#include "AppController.h"

int main() {
    AppController app;
    return app.run();
}
```

---

## 6. 단위 간 의존성

```
main.cpp
  └── AppController (SWE-UNIT-0003)
        ├── Calculator  (SWE-UNIT-0001)  ← types.h (SWE-UNIT-0004)
        └── InputParser (SWE-UNIT-0002)  ← types.h (SWE-UNIT-0004)
```

| 단위 ID | 의존 단위 ID | 의존 유형 |
|--------|-----------|---------|
| [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) | 타입 사용 (OperationResult) |
| [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) | 타입 사용 (ParsedInput, InputType) |
| [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | 함수 호출 (calculate) |
| [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) | 함수 호출 (parse) |
| [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) | 타입 사용 (OperationResult, ParsedInput) |

---

## 7. 코딩 규칙 연계

| 항목 | 규칙 | 근거 요구사항 |
|------|------|------------|
| 표준 준수 | C++17 (`-std=c++17`) | [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) |
| 헤더 가드 | `#pragma once` 사용 | 코딩 컨벤션 |
| 네이밍 | 클래스: PascalCase, 함수/변수: camelCase | 코딩 컨벤션 |
| 예외 처리 | C++ 예외(throw) 미사용 — 반환값 기반 오류 처리 | 단순성, 테스트 용이성 |
| 입력 스트림 | `std::istringstream` 사용하여 토큰 파싱 | C++17 준수 |
| 출력 스트림 | `std::cout` 사용, `std::endl` 대신 `"\n"` 권장 | 성능 |

---

## 8. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — 단위 4개 정의 (Calculator, InputParser, AppController, Types), 함수 인터페이스 및 알고리즘 명세 완료 | ASPICE SWE-3 전문가 |
