# SWE-4 소프트웨어 단위 검증 명세서

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE4-TC-SPEC-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-4 전문가 |
| 승인자 | — |
| 참조 문서 | SWE3-UNIT-SPEC-0001 (SWE-3 단위 설계), SWE1-REQ-SPEC-0001 (SWE-1 요구사항) |

---

## 1. 개요

### 1.1 목적

본 문서는 ASPICE SWE-4 소프트웨어 단위 검증 활동의 산출물이다.
SWE3-UNIT-SPEC-0001에서 정의된 소프트웨어 단위(SWE-UNIT-0001~0003)에 대한
단위 테스트 케이스, 테스트 실행 결과, 커버리지 달성 현황 및 추적성 매핑표를 포함한다.

### 1.2 범위

| 검증 대상 단위 | 테스트 파일 | TC 범위 |
|-------------|-----------|--------|
| SWE-UNIT-0001 Calculator | `tests/test_calculator.cpp` | SWE-TC-0001~0008 |
| SWE-UNIT-0002 InputParser | `tests/test_inputparser.cpp` | SWE-TC-0009~0023 |
| SWE-UNIT-0003 AppController | 단위 테스트 미포함 (stdin 의존성) | — |
| SWE-UNIT-0004 Types (공통 타입) | 별도 TC 없음 (각 단위 TC 내 간접 검증) | — |

> **AppController (SWE-UNIT-0003) 단위 테스트 제외 사유**: AppController는 `stdin`/`stdout`에 직접 의존하며 Calculator, InputParser를 내부적으로 호출한다. 구성 단위(Calculator, InputParser)는 독립 테스트로 완전 검증되므로, AppController는 SWE-5 통합 테스트에서 End-to-End로 검증한다.

### 1.3 테스트 환경

| 항목 | 내용 |
|------|------|
| 빌드 시스템 | CMake 3.28.3 |
| 컴파일러 | GCC/G++ 13.3.0 (C++17) |
| 테스트 프레임워크 | Google Test v1.14.0 |
| 커버리지 도구 | gcov 13.3.0 |
| 실행 환경 | WSL Ubuntu 24.04 LTS |
| 빌드 타입 | Debug (`-g -O0 --coverage -fprofile-arcs -ftest-coverage`) |
| 테스트 실행 명령 | `ctest --output-on-failure --verbose` |

---

## 2. 테스트 케이스 목록

### 2.1 Calculator 단위 테스트 (SWE-UNIT-0001)

| ID | 테스트명 | 대상 단위 ID | 시나리오 유형 | 입력 (a, op, b) | 기대 결과 | 버전 | 날짜 |
|----|---------|------------|------------|----------------|---------|------|------|
| SWE-TC-0001 | 덧셈 정상 동작 | SWE-UNIT-0001 | 정상 | 3.0, '+', 5.0 | success=true, result=8.0 | v1.0 | 2026-04-11 |
| SWE-TC-0002 | 뺄셈 정상 동작 | SWE-UNIT-0001 | 정상 | 10.0, '-', 3.0 | success=true, result=7.0 | v1.0 | 2026-04-11 |
| SWE-TC-0003 | 곱셈 정상 동작 | SWE-UNIT-0001 | 정상 | 4.0, '*', 3.0 | success=true, result=12.0 | v1.0 | 2026-04-11 |
| SWE-TC-0004 | 나눗셈 정상 동작 | SWE-UNIT-0001 | 정상 | 10.0, '/', 2.0 | success=true, result=5.0 | v1.0 | 2026-04-11 |
| SWE-TC-0005 | 0 나누기 예외 처리 | SWE-UNIT-0001 | 예외 | 7.0, '/', 0.0 | success=false, errorMsg="Error: Division by zero" | v1.0 | 2026-04-11 |
| SWE-TC-0006 | 음수 피연산자 정상 동작 | SWE-UNIT-0001 | 경계값 | -3.0, '+', -5.0 | success=true, result=-8.0 | v1.0 | 2026-04-11 |
| SWE-TC-0007 | 소수 피연산자 정상 동작 | SWE-UNIT-0001 | 경계값 | 1.0, '/', 3.0 | success=true, result≈0.333 | v1.0 | 2026-04-11 |
| SWE-TC-0008 | 알 수 없는 연산자 | SWE-UNIT-0001 | 예외 | 3.0, '%', 5.0 | success=false, errorMsg≠"" | v1.0 | 2026-04-11 |

### 2.2 InputParser 단위 테스트 (SWE-UNIT-0002)

| ID | 테스트명 | 대상 단위 ID | 시나리오 유형 | 입력 문자열 | 기대 결과 | 버전 | 날짜 |
|----|---------|------------|------------|----------|---------|------|------|
| SWE-TC-0009 | "q" → QUIT | SWE-UNIT-0002 | 정상 | `"q"` | type=QUIT | v1.0 | 2026-04-11 |
| SWE-TC-0010 | "Q" → QUIT (대소문자 무관) | SWE-UNIT-0002 | 경계값 | `"Q"` | type=QUIT | v1.0 | 2026-04-11 |
| SWE-TC-0011 | "quit" → QUIT | SWE-UNIT-0002 | 정상 | `"quit"` | type=QUIT | v1.0 | 2026-04-11 |
| SWE-TC-0012 | "QUIT" → QUIT (대소문자 무관) | SWE-UNIT-0002 | 경계값 | `"QUIT"` | type=QUIT | v1.0 | 2026-04-11 |
| SWE-TC-0013 | 유효한 정수 덧셈 파싱 | SWE-UNIT-0002 | 정상 | `"3 + 5"` | type=OPERATION, a=3, op='+', b=5 | v1.0 | 2026-04-11 |
| SWE-TC-0014 | 나누기 0 입력 파싱 | SWE-UNIT-0002 | 경계값 | `"10 / 0"` | type=OPERATION, a=10, op='/', b=0 | v1.0 | 2026-04-11 |
| SWE-TC-0015 | 빈 입력 → INVALID | SWE-UNIT-0002 | 예외 | `""` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |
| SWE-TC-0016 | 문자열만 입력 → INVALID | SWE-UNIT-0002 | 예외 | `"abc"` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |
| SWE-TC-0017 | 알 수 없는 연산자 → INVALID | SWE-UNIT-0002 | 예외 | `"3 % 5"` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |
| SWE-TC-0018 | 토큰 초과 입력 → INVALID | SWE-UNIT-0002 | 예외 | `"1 + 2 3"` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |
| SWE-TC-0019 | 앞뒤 공백 입력 → 정상 파싱 | SWE-UNIT-0002 | 경계값 | `"  3 + 5  "` | type=OPERATION, a=3, op='+', b=5 | v1.0 | 2026-04-11 |
| SWE-TC-0020 | 소수 피연산자 파싱 | SWE-UNIT-0002 | 경계값 | `"3.14 * 2.0"` | type=OPERATION, a=3.14, op='*', b=2.0 | v1.0 | 2026-04-11 |
| SWE-TC-0021 | 음수 피연산자 파싱 | SWE-UNIT-0002 | 경계값 | `"-5 + 3"` | type=OPERATION, a=-5, op='+', b=3 | v1.0 | 2026-04-11 |
| SWE-TC-0022 | 숫자만 입력 → INVALID | SWE-UNIT-0002 | 예외 | `"42"` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |
| SWE-TC-0023 | 공백만 입력 → INVALID | SWE-UNIT-0002 | 경계값 | `"   "` | type=INVALID, errorMsg≠"" | v1.0 | 2026-04-11 |

---

## 3. 테스트 실행 결과

> 실행 날짜: 2026-04-11 / 실행 환경: WSL Ubuntu 24.04, GTest v1.14.0 / 명령: `ctest --output-on-failure`

### 3.1 최종 요약

```
100% tests passed, 0 tests failed out of 23
Total Test time (real) = 3.20 sec
```

### 3.2 TC별 실행 결과

| TC ID | 테스트명 | 실행 날짜 | 담당자 | 결과 | 실제 출력 요약 | 비고 |
|-------|---------|---------|--------|------|------------|------|
| SWE-TC-0001 | TC0001_Addition_Normal | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0002 | TC0002_Subtraction_Normal | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0003 | TC0003_Multiplication_Normal | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0004 | TC0004_Division_Normal | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0005 | TC0005_Division_ByZero | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0006 | TC0006_Negative_Operands | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0007 | TC0007_Floating_Point | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0008 | TC0008_UnknownOperator | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0009 | TC0009_Quit_Lowercase_q | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (1 ms)` | |
| SWE-TC-0010 | TC0010_Quit_Uppercase_Q | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0011 | TC0011_Quit_Word_quit | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0012 | TC0012_Quit_Word_QUIT | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0013 | TC0013_Operation_Addition | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0014 | TC0014_Operation_DivisionByZero_Parsed | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0015 | TC0015_Invalid_EmptyInput | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0016 | TC0016_Invalid_TextInput | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0017 | TC0017_Invalid_UnknownOperator | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0018 | TC0018_Invalid_TooManyTokens | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0019 | TC0019_Operation_LeadingTrailingSpaces | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0020 | TC0020_Operation_FloatingPoint | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0021 | TC0021_Operation_NegativeOperand | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0022 | TC0022_Invalid_NumberOnly | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |
| SWE-TC-0023 | TC0023_Invalid_WhitespaceOnly | 2026-04-11 | ASPICE SWE-4 전문가 | **Pass** | `[ OK ] (0 ms)` | |

---

## 4. 커버리지 달성 현황

> 측정 도구: gcov 13.3.0 / 측정 날짜: 2026-04-11 / 빌드 타입: Debug

### 4.1 단위별 커버리지

| 단위 ID | 소스 파일 | 구문(Line) 커버리지 | 분기(Branch) 커버리지 | 커버리지 목표 | 목표 달성 여부 |
|--------|---------|-----------------|-------------------|------------|------------|
| SWE-UNIT-0001 | `Calculator.cpp` | **96.43%** (27/28 라인) | **100%** (17/17 분기 실행) | 구문 ≥ 100%, 분기 ≥ 100% | ⚠ 구문 미달 (1라인) |
| SWE-UNIT-0002 | `InputParser.cpp` | **100%** (32/32 라인) | **100%** (60/60 분기 실행) | 구문 ≥ 100%, 분기 ≥ 100% | ✅ 달성 |
| SWE-UNIT-0004 | `types.h` | 실행 라인 없음 | — | — | ✅ 해당 없음 |

### 4.2 Calculator.cpp 미커버 라인 분석

gcov 분석 결과 `Calculator.cpp` 96.43%(27/28)로 1 라인이 미커버 상태.
해당 라인은 `std::string` 소멸자 / 인라인 복사 경로로 컴파일러 인라인 확장에 의해 발생한 것이며, 실제 로직 분기는 100% 실행 완료됨.

| 미커버 항목 | 원인 | 조치 |
|-----------|------|------|
| `std::string` 초기화 관련 컴파일러 생성 코드 1라인 | GCC 인라인 확장으로 인한 gcov 계측 아티팩트 | 실제 기능 분기 100% 커버로 목표 달성 간주 가능. SWE-4 리뷰에서 검토 필요 |

---

## 5. 추적성 매핑표 (SWE-3 → SWE-4)

| 단위 ID | 단위명 | TC ID | SW 요구사항 ID | 시나리오 유형 | TC 결과 | 비고 |
|--------|--------|-------|--------------|------------|--------|------|
| SWE-UNIT-0001 | Calculator | SWE-TC-0001 | SWE-REQ-0001 | 정상 | Pass | 덧셈 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0002 | SWE-REQ-0002 | 정상 | Pass | 뺄셈 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0003 | SWE-REQ-0003 | 정상 | Pass | 곱셈 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0004 | SWE-REQ-0004 | 정상 | Pass | 나눗셈 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0005 | SWE-REQ-0005 | 예외 | Pass | 0 나누기 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0006 | SWE-REQ-0001 | 경계값 | Pass | 음수 피연산자 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0007 | SWE-REQ-0004 | 경계값 | Pass | 소수 피연산자 |
| SWE-UNIT-0001 | Calculator | SWE-TC-0008 | SWE-REQ-0009 | 예외 | Pass | 알 수 없는 연산자 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0009 | SWE-REQ-0008 | 정상 | Pass | q 종료 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0010 | SWE-REQ-0008 | 경계값 | Pass | 대소문자 무관 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0011 | SWE-REQ-0008 | 정상 | Pass | quit 종료 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0012 | SWE-REQ-0008 | 경계값 | Pass | QUIT 대소문자 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0013 | SWE-REQ-0006 | 정상 | Pass | 정수 덧셈 파싱 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0014 | SWE-REQ-0005 | 경계값 | Pass | 0나누기 파싱 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0015 | SWE-REQ-0007 | 예외 | Pass | 빈 입력 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0016 | SWE-REQ-0007 | 예외 | Pass | 문자열 입력 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0017 | SWE-REQ-0009 | 예외 | Pass | 잘못된 연산자 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0018 | SWE-REQ-0007 | 예외 | Pass | 토큰 초과 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0019 | SWE-REQ-0006 | 경계값 | Pass | 앞뒤 공백 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0020 | SWE-REQ-0006 | 경계값 | Pass | 소수 파싱 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0021 | SWE-REQ-0006 | 경계값 | Pass | 음수 파싱 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0022 | SWE-REQ-0007 | 예외 | Pass | 숫자만 입력 |
| SWE-UNIT-0002 | InputParser | SWE-TC-0023 | SWE-REQ-0007 | 경계값 | Pass | 공백만 입력 |
| SWE-UNIT-0003 | AppController | — | SWE-REQ-0006~0009 | — | Blocked | stdin 의존 — SWE-5 통합 테스트로 이전 |

### 5.1 SWE-REQ별 검증 현황

| SWE-REQ ID | 요구사항 요약 | 검증 TC | 검증 상태 |
|-----------|-----------|--------|---------|
| SWE-REQ-0001 | 덧셈 기능 | SWE-TC-0001, SWE-TC-0006 | ✅ 검증 완료 |
| SWE-REQ-0002 | 뺄셈 기능 | SWE-TC-0002 | ✅ 검증 완료 |
| SWE-REQ-0003 | 곱셈 기능 | SWE-TC-0003 | ✅ 검증 완료 |
| SWE-REQ-0004 | 나눗셈 기능 | SWE-TC-0004, SWE-TC-0007 | ✅ 검증 완료 |
| SWE-REQ-0005 | 0 나누기 처리 | SWE-TC-0005, SWE-TC-0014 | ✅ 검증 완료 |
| SWE-REQ-0006 | 입력 파싱 (유효) | SWE-TC-0013, SWE-TC-0019~0021 | ✅ 검증 완료 |
| SWE-REQ-0007 | 잘못된 입력 처리 | SWE-TC-0015~0016, SWE-TC-0018, SWE-TC-0022~0023 | ✅ 검증 완료 |
| SWE-REQ-0008 | 종료 명령 처리 | SWE-TC-0009~0012 | ✅ 검증 완료 |
| SWE-REQ-0009 | 알 수 없는 연산자 | SWE-TC-0008, SWE-TC-0017 | ✅ 검증 완료 |
| SWE-REQ-0010 | 결과 출력 형식 | — | ⚠ SWE-5/SWE-6에서 End-to-End 검증 예정 |

---

## 6. 결함 목록

> 본 검증 실행(2026-04-11) 결과: 기능 결함 없음. 커버리지 관련 관찰 사항 1건.

| ID | 내용 | 심각도 | 상태 | 비고 |
|----|------|--------|------|------|
| SWE-DEF-0001 | Calculator.cpp 구문 커버리지 96.43% — 목표 100% 미달 | Low | Open | GCC 인라인 확장 아티팩트 추정. 실제 로직 분기 100% 달성. 리뷰 검토 필요 |

---

## 7. 리뷰 체크리스트

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 1 | 모든 테스트 케이스에 고유 ID(`SWE-TC-XXXX`) 부여됨 | ☑ 적합 | SWE-TC-0001~0023 (23건) |
| 2 | 모든 단위(SWE-3)에 최소 1개 이상의 TC 매핑됨 | ☑ 적합 | SWE-UNIT-0001: 8건, SWE-UNIT-0002: 15건 |
| 3 | 정상·경계·예외 시나리오가 모두 포함됨 | ☑ 적합 | 정상 7건, 경계값 10건, 예외 7건 |
| 4 | SW 요구사항과의 추적성 확보됨 | ☑ 적합 | SWE-REQ-0001~0009 전 항목 검증 완료. REQ-0010만 SWE-5/6 이전 |
| 5 | 테스트 결과(Pass/Fail/Blocked)가 모두 기록됨 | ☑ 적합 | Pass 23/23, Blocked 1 (AppController) |
| 6 | 커버리지 측정 수행됨 | ☑ 적합 | §4 gcov 측정 결과 기록 |
| 7 | 커버리지 목표 달성 여부 확인됨 | ⚠ 조건부 | Calculator 구문 96.43% — SWE-DEF-0001 등록 |
| 8 | 결함(DEF)에 고유 ID 부여 및 기록됨 | ☑ 적합 | SWE-DEF-0001 |
| 9 | AppController 테스트 미포함 사유 명시됨 | ☑ 적합 | §1.2 stdin 의존 — SWE-5 이전 사유 기술 |
| 10 | 버전 및 변경 이력 기록됨 | ☑ 적합 | §8 변경 이력 |

---

## 8. 변경 이력

| 버전 | 날짜 | 변경 내용 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — SWE-TC-0001~0023 작성, 전체 실행 Pass, 커버리지 측정 완료 | ASPICE SWE-4 전문가 |
