# SWE-2 소프트웨어 아키텍처 설계서

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE2-ARCH-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-2 전문가 |
| 승인자 | — |
| 참조 문서 | SWE1-REQ-SPEC-0001 (SWE-1 요구사항 명세서), MAN3-PP-0001 (프로젝트 계획서) |

---

## 1. 개요

### 1.1 목적

본 문서는 CLI 계산기 소프트웨어의 소프트웨어 아키텍처를 정의한다.
SWE-1에서 도출된 SW 요구사항(SWE-REQ-0001~SWE-REQ-0010)을 컴포넌트로 분해하고,
컴포넌트 간 인터페이스를 명세하여 SWE-3 상세 설계의 기반을 제공한다.

### 1.2 범위

- 대상 소프트웨어: CLI 계산기 (`calculator`)
- 실행 환경: Ubuntu 22.04 LTS, CLI (표준 입출력)
- 구현 언어: C++17

### 1.3 설계 원칙

- **단일 책임 원칙(SRP)**: 각 컴포넌트는 하나의 책임만 가진다.
- **낮은 결합도(Low Coupling)**: 컴포넌트 간 의존은 인터페이스를 통해서만 이루어진다.
- **테스트 용이성**: 컴포넌트 단위로 독립 테스트가 가능해야 한다.

---

## 2. 컴포넌트 분해

### 2.1 컴포넌트 목록

| ID | 컴포넌트명 | 책임 | 관련 요구사항 | 버전 | 날짜 | 상태 |
|----|-----------|------|-------------|------|------|------|
| SWE-COMP-0001 | Calculator | 4칙 연산(덧셈·뺄셈·곱셈·나눗셈) 수행 및 0 나누기 예외 처리 | SWE-REQ-0001~0005 | v1.0 | 2026-04-11 | Draft |
| SWE-COMP-0002 | InputParser | 표준 입력(stdin)으로부터 연산식(`<피연산자> <연산자> <피연산자>`) 파싱 및 종료 명령 인식 | SWE-REQ-0006, SWE-REQ-0008 | v1.0 | 2026-04-11 | Draft |
| SWE-COMP-0003 | AppController | 반복 입력 루프 제어, 종료 명령 처리, 결과/오류 메시지 표준 출력 | SWE-REQ-0007, SWE-REQ-0008 | v1.0 | 2026-04-11 | Draft |

### 2.2 컴포넌트 상세 설명

#### SWE-COMP-0001 — Calculator

| 항목 | 내용 |
|------|------|
| ID | SWE-COMP-0001 |
| 컴포넌트명 | Calculator |
| 책임 | 두 개의 `double` 피연산자와 연산자를 입력받아 연산 결과를 반환. 나눗셈 시 제수가 0이면 예외 처리 후 오류 결과 반환 |
| 제공 인터페이스 | SWE-IF-0002 (OperationResult 반환) |
| 소비 인터페이스 | SWE-IF-0001 (OperationRequest 수신) |
| 주요 함수 | `calculate(a: double, op: char, b: double) → OperationResult` |
| 비고 | C++17 준수 (SWE-REQ-0009), 단위 테스트 커버리지 100% 대상 (SWE-REQ-0010) |

#### SWE-COMP-0002 — InputParser

| 항목 | 내용 |
|------|------|
| ID | SWE-COMP-0002 |
| 컴포넌트명 | InputParser |
| 책임 | stdin에서 한 줄을 읽어 `<피연산자A> <연산자> <피연산자B>` 형식으로 파싱. `q`/`quit` 입력 시 종료 신호 반환. 잘못된 형식 입력 시 오류 신호 반환 |
| 제공 인터페이스 | SWE-IF-0003 (ParsedInput 반환) |
| 소비 인터페이스 | 없음 (stdin 직접 읽기) |
| 주요 함수 | `parse(line: string) → ParsedInput` |
| 비고 | C++17 준수 (SWE-REQ-0009) |

#### SWE-COMP-0003 — AppController

| 항목 | 내용 |
|------|------|
| ID | SWE-COMP-0003 |
| 컴포넌트명 | AppController |
| 책임 | 프로그램 진입점. 반복 루프를 관리하며 InputParser를 통해 사용자 입력을 받고, Calculator에 연산을 요청하고, 결과/오류를 stdout에 출력. 종료 명령 수신 시 exit code 0으로 정상 종료 |
| 제공 인터페이스 | 없음 (최상위 컨트롤러) |
| 소비 인터페이스 | SWE-IF-0001 (OperationRequest 공급), SWE-IF-0002 (OperationResult 수신), SWE-IF-0003 (ParsedInput 수신) |
| 주요 함수 | `run() → int` (exit code) |
| 비고 | C++17 준수 (SWE-REQ-0009) |

---

## 3. 인터페이스 정의

### 3.1 인터페이스 목록

| ID | 제공 컴포넌트 | 소비 컴포넌트 | 데이터/신호 | 프로토콜 | 비고 |
|----|-------------|-------------|------------|---------|------|
| SWE-IF-0001 | AppController | Calculator | `OperationRequest {operandA: double, op: char, operandB: double}` | 함수 호출 (C++ 메서드) | AppController가 Calculator의 calculate() 호출 |
| SWE-IF-0002 | Calculator | AppController | `OperationResult {success: bool, result: double, errorMsg: string}` | 함수 반환값 (C++ return) | 0 나누기 시 success=false, errorMsg 설정 |
| SWE-IF-0003 | InputParser | AppController | `ParsedInput {type: enum{OPERATION, QUIT, INVALID}, operandA: double, op: char, operandB: double, errorMsg: string}` | 함수 반환값 (C++ return) | QUIT 시 루프 종료, INVALID 시 오류 메시지 출력 |

### 3.2 인터페이스 상세 명세

#### SWE-IF-0001 — OperationRequest

| 항목 | 내용 |
|------|------|
| ID | SWE-IF-0001 |
| 방향 | AppController → Calculator |
| 타입 | 함수 호출 파라미터 |
| 데이터 구조 | `operandA: double`, `op: char (+, -, *, /)`, `operandB: double` |
| 유효성 조건 | `op`는 `+`, `-`, `*`, `/` 중 하나 |
| 관련 요구사항 | SWE-REQ-0001~0005 |

#### SWE-IF-0002 — OperationResult

| 항목 | 내용 |
|------|------|
| ID | SWE-IF-0002 |
| 방향 | Calculator → AppController |
| 타입 | 함수 반환값 |
| 데이터 구조 | `success: bool`, `result: double`, `errorMsg: string` |
| 성공 케이스 | `success = true`, `result = 연산 결과` |
| 실패 케이스 | `success = false`, `errorMsg = "Error: Division by zero"` |
| 관련 요구사항 | SWE-REQ-0001~0005 |

#### SWE-IF-0003 — ParsedInput

| 항목 | 내용 |
|------|------|
| ID | SWE-IF-0003 |
| 방향 | InputParser → AppController |
| 타입 | 함수 반환값 |
| 데이터 구조 | `type: enum{OPERATION, QUIT, INVALID}`, `operandA: double`, `op: char`, `operandB: double`, `errorMsg: string` |
| OPERATION | 정상 연산식 파싱 완료 |
| QUIT | `q` 또는 `quit` 입력 감지 |
| INVALID | 잘못된 형식 입력, `errorMsg`에 오류 내용 포함 |
| 관련 요구사항 | SWE-REQ-0006~0008 |

---

## 4. 정적 구조 설계

### 4.1 컴포넌트 구성도 (텍스트 표현)

```
┌────────────────────────────────────────────────────────────┐
│                      calculator (실행 파일)                  │
│                                                            │
│  ┌──────────────────────────────────────────────────────┐  │
│  │                  AppController                        │  │
│  │  SWE-COMP-0003                                        │  │
│  │  - run() : int                                        │  │
│  └────────┬─────────────────────┬────────────────────────┘  │
│           │ SWE-IF-0003         │ SWE-IF-0001 / SWE-IF-0002 │
│           ▼                     ▼                           │
│  ┌─────────────────┐   ┌─────────────────────────────────┐  │
│  │  InputParser    │   │         Calculator               │  │
│  │  SWE-COMP-0002  │   │         SWE-COMP-0001            │  │
│  │  - parse()      │   │  - calculate(a, op, b)           │  │
│  │    : ParsedInput│   │    : OperationResult             │  │
│  └────────┬────────┘   └─────────────────────────────────┘  │
│           │ stdin                                           │
└───────────┼────────────────────────────────────────────────┘
            ▼
         사용자 (CLI)
```

### 4.2 파일 구조 (예상)

```
src/
├── main.cpp                  # AppController 진입점
├── AppController.h / .cpp    # SWE-COMP-0003
├── Calculator.h / .cpp       # SWE-COMP-0001
└── InputParser.h / .cpp      # SWE-COMP-0002
```

---

## 5. 동적 행위 설계

### 5.1 정상 연산 시퀀스

```
사용자          AppController        InputParser         Calculator
  │                  │                   │                    │
  │ "3.0 + 5.0\n"    │                   │                    │
  │─────────────────>│                   │                    │
  │                  │ parse(line)       │                    │
  │                  │──────────────────>│                    │
  │                  │  ParsedInput      │                    │
  │                  │  {OPERATION,      │                    │
  │                  │   3.0, '+', 5.0}  │                    │
  │                  │<──────────────────│                    │
  │                  │ calculate(3.0,'+',5.0)                 │
  │                  │───────────────────────────────────────>│
  │                  │         OperationResult{true, 8.0, ""}  │
  │                  │<───────────────────────────────────────│
  │ "Result: 8.0"    │                   │                    │
  │<─────────────────│                   │                    │
```

### 5.2 0 나누기 예외 시퀀스

```
사용자          AppController        InputParser         Calculator
  │                  │                   │                    │
  │ "5.0 / 0.0\n"   │                   │                    │
  │─────────────────>│                   │                    │
  │                  │ parse(line)       │                    │
  │                  │──────────────────>│                    │
  │                  │  ParsedInput      │                    │
  │                  │  {OPERATION,      │                    │
  │                  │   5.0, '/', 0.0}  │                    │
  │                  │<──────────────────│                    │
  │                  │ calculate(5.0,'/',0.0)                 │
  │                  │───────────────────────────────────────>│
  │                  │  OperationResult{false, 0.0,           │
  │                  │  "Error: Division by zero"}            │
  │                  │<───────────────────────────────────────│
  │ "Error: ..."     │                   │                    │
  │<─────────────────│                   │                    │
  │ (루프 유지)       │                   │                    │
```

### 5.3 종료 명령 시퀀스

```
사용자          AppController        InputParser
  │                  │                   │
  │ "q\n"            │                   │
  │─────────────────>│                   │
  │                  │ parse("q")        │
  │                  │──────────────────>│
  │                  │  ParsedInput{QUIT}│
  │                  │<──────────────────│
  │                  │ (루프 종료)        │
  │                  │ exit(0)           │
```

---

## 6. 비기능 요구사항 대응

| 요구사항 ID | 내용 | 아키텍처 대응 |
|------------|------|-------------|
| SWE-REQ-0009 | C++17 준수 | 모든 컴포넌트(SWE-COMP-0001~0003) C++17 표준으로 구현. 빌드 시 `-std=c++17` 플래그 적용 |
| SWE-REQ-0010 | 문장/분기 커버리지 100% | SWE-COMP-0001(Calculator), SWE-COMP-0002(InputParser)를 독립 클래스로 분리하여 단위 테스트 가능한 구조 확보 |

---

## 7. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — 컴포넌트 3개, 인터페이스 3개 정의 | ASPICE SWE-2 전문가 |
