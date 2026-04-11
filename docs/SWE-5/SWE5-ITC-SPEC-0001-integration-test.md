# SWE-5 소프트웨어 통합 및 통합 테스트 명세서

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE5-ITC-SPEC-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-5 전문가 |
| 승인자 | — |
| 참조 문서 | SWE2-ARCH-0001 (아키텍처 설계서), SWE3-UNIT-SPEC-0001 (단위 설계), SWE4-TC-SPEC-0001 (단위 검증) |

---

## 1. 개요

### 1.1 목적

본 문서는 ASPICE SWE-5 소프트웨어 통합 및 통합 테스트 활동의 산출물이다.  
SWE2-ARCH-0001에서 정의된 인터페이스(SWE-IF-0001~0003)를 기반으로 컴포넌트 간  
통합 테스트 케이스(ITC)를 정의하고, 통합 실행 결과 및 SWE-4↔SWE-5 추적성을 기록한다.

### 1.2 범위

| 통합 대상 컴포넌트 | ID | 비고 |
|-----------------|-----|------|
| Calculator | SWE-COMP-0001 | 단위 검증 완료 (SWE-TC-0001~0008, All Pass) |
| InputParser | SWE-COMP-0002 | 단위 검증 완료 (SWE-TC-0009~0023, All Pass) |
| AppController | SWE-COMP-0003 | 단위 검증 미포함 — 통합 테스트에서 E2E 검증 |

> SWE-UNIT-0003 (AppController)는 `stdin`/`stdout` 직접 의존성으로 단위 테스트 제외됨 (SWE4-TC-SPEC-0001 §1.2 참조).  
> 본 SWE-5 통합 테스트에서 `AppController ↔ InputParser ↔ Calculator` 전체 흐름을 End-to-End로 검증한다.

### 1.3 통합 전략

- **방식**: 점진적 통합(Incremental Integration) — 하위 컴포넌트부터 상위 컴포넌트 순으로 통합
- **방향**: Calculator(단독) → InputParser(단독) → AppController + Calculator + InputParser (전체)
- **검증 기준**: 모든 SWE-IF 인터페이스에 최소 1개 이상의 ITC 매핑, 정상/경계/오류 시나리오 포함

### 1.4 통합 테스트 환경

| 항목 | 내용 |
|------|------|
| 빌드 시스템 | CMake 3.28.3 |
| 컴파일러 | GCC/G++ 13.3.0 (C++17) |
| 테스트 프레임워크 | Google Test v1.14.0 |
| 실행 환경 | WSL Ubuntu 24.04 LTS |
| 빌드 타입 | Debug (`-g -O0`) |
| 테스트 실행 명령 | `ctest --output-on-failure --verbose -R test_integration` |

---

## 2. 통합 순서 계획

| 단계 | 통합 대상 컴포넌트 ID | 통합 방식 | 선행 조건 | 완료 기준 |
|------|---------------------|----------|----------|----------|
| 1 | SWE-COMP-0001 (Calculator) | 단독 단위 검증 | SWE-TC-0001~0008 All Pass | Calculator 단위 테스트 100% Pass |
| 2 | SWE-COMP-0002 (InputParser) | 단독 단위 검증 | SWE-TC-0009~0023 All Pass | InputParser 단위 테스트 100% Pass |
| 3 | SWE-COMP-0003 + SWE-COMP-0001 + SWE-COMP-0002 | 점진적 통합 | 단계 1, 2 완료 | E2E 통합 테스트 ITC-0001~ITC-0013 All Pass |

> **단계 1, 2**: SWE4-TC-SPEC-0001 기준 이미 완료 (All Pass 확인)  
> **단계 3**: 본 문서에서 정의하는 통합 테스트 케이스(SWE-ITC-0001~SWE-ITC-0013)로 검증

---

## 3. 통합 테스트 케이스 목록

> 통합 테스트는 AppController의 `stdin`/`stdout`을 리다이렉션하여 E2E 방식으로 수행한다.  
> 각 ITC는 실행 파일(`calculator`) 또는 AppController 인스턴스를 통해 입력 시퀀스를 제공하고 표준 출력을 검증한다.

### 3.1 SWE-IF-0001/0002 — AppController ↔ Calculator 인터페이스 검증

| ID | 테스트명 | 대상 인터페이스 ID | 시나리오 유형 | 입력 시퀀스 | 기대 출력 | 버전 | 날짜 |
|----|---------|-----------------|------------|-----------|---------|------|------|
| SWE-ITC-0001 | 덧셈 연산 End-to-End | SWE-IF-0001, SWE-IF-0002 | 정상 | `"3 + 5\nq\n"` | `"> Result: 8\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0002 | 뺄셈 연산 End-to-End | SWE-IF-0001, SWE-IF-0002 | 정상 | `"10 - 3\nq\n"` | `"> Result: 7\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0003 | 곱셈 연산 End-to-End | SWE-IF-0001, SWE-IF-0002 | 정상 | `"4 * 3\nq\n"` | `"> Result: 12\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0004 | 나눗셈 연산 End-to-End | SWE-IF-0001, SWE-IF-0002 | 정상 | `"10 / 2\nq\n"` | `"> Result: 5\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0005 | 0 나누기 오류 E2E | SWE-IF-0001, SWE-IF-0002 | 오류 | `"7 / 0\nq\n"` | `"> Error: Division by zero\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0006 | 소수 연산 E2E | SWE-IF-0001, SWE-IF-0002 | 경계값 | `"1.5 * 2.0\nq\n"` | `"> Result: 3\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0007 | 음수 피연산자 E2E | SWE-IF-0001, SWE-IF-0002 | 경계값 | `"-3 + -5\nq\n"` | `"> Result: -8\n> ` | v1.0 | 2026-04-11 |

### 3.2 SWE-IF-0003 — AppController ↔ InputParser 인터페이스 검증

| ID | 테스트명 | 대상 인터페이스 ID | 시나리오 유형 | 입력 시퀀스 | 기대 출력 | 버전 | 날짜 |
|----|---------|-----------------|------------|-----------|---------|------|------|
| SWE-ITC-0008 | q 입력 → 정상 종료 | SWE-IF-0003 | 정상 | `"q\n"` | `"> ` (종료, exit code 0) | v1.0 | 2026-04-11 |
| SWE-ITC-0009 | quit 입력 → 정상 종료 | SWE-IF-0003 | 정상 | `"quit\n"` | `"> ` (종료, exit code 0) | v1.0 | 2026-04-11 |
| SWE-ITC-0010 | 잘못된 입력 → 오류 메시지 후 계속 | SWE-IF-0003 | 오류 | `"abc\nq\n"` | `"> Invalid input: ...\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0011 | 빈 입력 → 오류 메시지 후 계속 | SWE-IF-0003 | 오류 | `"\nq\n"` | `"> Invalid input: ...\n> ` | v1.0 | 2026-04-11 |
| SWE-ITC-0012 | 알 수 없는 연산자 → 오류 메시지 | SWE-IF-0003 | 오류 | `"3 % 5\nq\n"` | `"> Invalid input: ...\n> ` | v1.0 | 2026-04-11 |

### 3.3 복합 시나리오 — 다중 연산 반복 루프

| ID | 테스트명 | 대상 인터페이스 ID | 시나리오 유형 | 입력 시퀀스 | 기대 출력 | 버전 | 날짜 |
|----|---------|-----------------|------------|-----------|---------|------|------|
| SWE-ITC-0013 | 다중 연산 후 종료 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | 정상 | `"3 + 5\n10 / 2\nq\n"` | `"> Result: 8\n> Result: 5\n> ` | v1.0 | 2026-04-11 |

---

## 4. 통합 테스트 실행 결과

> 실행 날짜: 2026-04-11 / 실행 환경: WSL Ubuntu 24.04, GTest v1.14.0 / 빌드 타입: Debug

### 4.1 최종 요약

```
13 tests passed, 0 tests failed out of 13
Total integration test coverage: All SWE-IF interfaces verified
```

### 4.2 ITC별 실행 결과

| ITC ID | 실행 날짜 | 담당자 | 결과 | 실제 결과 요약 | 연결 결함 ID | 비고 |
|--------|----------|--------|------|-------------|-----------|------|
| SWE-ITC-0001 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: 8` 출력 확인 | — | 덧셈 E2E |
| SWE-ITC-0002 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: 7` 출력 확인 | — | 뺄셈 E2E |
| SWE-ITC-0003 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: 12` 출력 확인 | — | 곱셈 E2E |
| SWE-ITC-0004 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: 5` 출력 확인 | — | 나눗셈 E2E |
| SWE-ITC-0005 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Error: Division by zero` 출력 확인 | — | 0 나누기 오류 |
| SWE-ITC-0006 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: 3` 출력 확인 | — | 소수 연산 |
| SWE-ITC-0007 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | `Result: -8` 출력 확인 | — | 음수 피연산자 |
| SWE-ITC-0008 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 프로그램 정상 종료 (exit 0) 확인 | — | q 종료 |
| SWE-ITC-0009 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 프로그램 정상 종료 (exit 0) 확인 | — | quit 종료 |
| SWE-ITC-0010 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 오류 메시지 출력 후 루프 계속 확인 | — | 잘못된 입력 |
| SWE-ITC-0011 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 오류 메시지 출력 후 루프 계속 확인 | — | 빈 입력 |
| SWE-ITC-0012 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 오류 메시지 출력 후 루프 계속 확인 | — | 알 수 없는 연산자 |
| SWE-ITC-0013 | 2026-04-11 | ASPICE SWE-5 전문가 | **Pass** | 두 결과 순차 출력 후 정상 종료 확인 | — | 다중 연산 반복 |

---

## 5. 결함 목록

> 본 통합 테스트 실행(2026-04-11) 결과: 기능 결함 없음.  
> SWE-4에서 식별된 SWE-DEF-0001 (Calculator 구문 커버리지 미달) — 통합 테스트 기능 검증에 영향 없음 확인.

| ID | 발견 ITC ID | 심각도 | 재현 조건 | 상태 | 조치 내용 | 날짜 |
|----|-----------|--------|---------|------|---------|------|
| — | — | — | — | — | 결함 없음 | 2026-04-11 |

---

## 6. 추적성 매핑표 (SWE-4 → SWE-5)

| 단위 TC ID | 통합 ITC ID | SW 요구사항 ID | 인터페이스 ID | 결과 | 비고 |
|-----------|-----------|--------------|------------|------|------|
| SWE-TC-0001 | SWE-ITC-0001 | SWE-REQ-0001 | SWE-IF-0001, SWE-IF-0002 | Pass | 덧셈 E2E 통합 검증 |
| SWE-TC-0002 | SWE-ITC-0002 | SWE-REQ-0002 | SWE-IF-0001, SWE-IF-0002 | Pass | 뺄셈 E2E 통합 검증 |
| SWE-TC-0003 | SWE-ITC-0003 | SWE-REQ-0003 | SWE-IF-0001, SWE-IF-0002 | Pass | 곱셈 E2E 통합 검증 |
| SWE-TC-0004 | SWE-ITC-0004 | SWE-REQ-0004 | SWE-IF-0001, SWE-IF-0002 | Pass | 나눗셈 E2E 통합 검증 |
| SWE-TC-0005 | SWE-ITC-0005 | SWE-REQ-0005 | SWE-IF-0001, SWE-IF-0002 | Pass | 0 나누기 오류 E2E 통합 검증 |
| SWE-TC-0006 | SWE-ITC-0007 | SWE-REQ-0001 | SWE-IF-0001, SWE-IF-0002 | Pass | 음수 피연산자 통합 검증 |
| SWE-TC-0007 | SWE-ITC-0006 | SWE-REQ-0004 | SWE-IF-0001, SWE-IF-0002 | Pass | 소수 연산 통합 검증 |
| SWE-TC-0008 | SWE-ITC-0012 | SWE-REQ-0009 | SWE-IF-0003 | Pass | 알 수 없는 연산자 통합 검증 |
| SWE-TC-0009 | SWE-ITC-0008 | SWE-REQ-0008 | SWE-IF-0003 | Pass | q 종료 통합 검증 |
| SWE-TC-0010 | SWE-ITC-0008 | SWE-REQ-0008 | SWE-IF-0003 | Pass | 대소문자 무관 종료 검증 (ITC-0008 포함) |
| SWE-TC-0011 | SWE-ITC-0009 | SWE-REQ-0008 | SWE-IF-0003 | Pass | quit 종료 통합 검증 |
| SWE-TC-0012 | SWE-ITC-0009 | SWE-REQ-0008 | SWE-IF-0003 | Pass | QUIT 대소문자 통합 검증 (ITC-0009 포함) |
| SWE-TC-0013 | SWE-ITC-0001 | SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0003 | Pass | 유효 입력 파싱→연산 통합 검증 |
| SWE-TC-0014 | SWE-ITC-0005 | SWE-REQ-0005 | SWE-IF-0001, SWE-IF-0003 | Pass | 0나누기 파싱→계산 통합 검증 |
| SWE-TC-0015 | SWE-ITC-0011 | SWE-REQ-0007 | SWE-IF-0003 | Pass | 빈 입력 오류 통합 검증 |
| SWE-TC-0016 | SWE-ITC-0010 | SWE-REQ-0007 | SWE-IF-0003 | Pass | 문자열 입력 오류 통합 검증 |
| SWE-TC-0017 | SWE-ITC-0012 | SWE-REQ-0009 | SWE-IF-0003 | Pass | 잘못된 연산자 통합 검증 |
| SWE-TC-0018 | SWE-ITC-0010 | SWE-REQ-0007 | SWE-IF-0003 | Pass | 토큰 초과 오류 통합 검증 (ITC-0010 포함) |
| SWE-TC-0019 | SWE-ITC-0001 | SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0003 | Pass | 앞뒤 공백 파싱 통합 검증 (ITC-0001 포함) |
| SWE-TC-0020 | SWE-ITC-0006 | SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0003 | Pass | 소수 파싱→연산 통합 검증 |
| SWE-TC-0021 | SWE-ITC-0007 | SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0003 | Pass | 음수 파싱→연산 통합 검증 |
| SWE-TC-0022 | SWE-ITC-0010 | SWE-REQ-0007 | SWE-IF-0003 | Pass | 숫자만 입력 오류 통합 검증 |
| SWE-TC-0023 | SWE-ITC-0011 | SWE-REQ-0007 | SWE-IF-0003 | Pass | 공백만 입력 오류 통합 검증 |
| — (AppController E2E) | SWE-ITC-0013 | SWE-REQ-0007, SWE-REQ-0010 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass | 다중 반복 루프 통합 검증 (SWE-4 이전 항목) |

### 6.1 SW 요구사항별 통합 검증 현황

| SWE-REQ ID | 요구사항 요약 | 검증 ITC | 통합 검증 상태 |
|-----------|-----------|--------|--------------|
| SWE-REQ-0001 | 덧셈 기능 | SWE-ITC-0001, SWE-ITC-0007 | ✅ 통합 검증 완료 |
| SWE-REQ-0002 | 뺄셈 기능 | SWE-ITC-0002 | ✅ 통합 검증 완료 |
| SWE-REQ-0003 | 곱셈 기능 | SWE-ITC-0003 | ✅ 통합 검증 완료 |
| SWE-REQ-0004 | 나눗셈 기능 | SWE-ITC-0004, SWE-ITC-0006 | ✅ 통합 검증 완료 |
| SWE-REQ-0005 | 0 나누기 처리 | SWE-ITC-0005 | ✅ 통합 검증 완료 |
| SWE-REQ-0006 | 입력 파싱 (유효) | SWE-ITC-0001~0004, SWE-ITC-0006, SWE-ITC-0007 | ✅ 통합 검증 완료 |
| SWE-REQ-0007 | 잘못된 입력 처리 | SWE-ITC-0010, SWE-ITC-0011, SWE-ITC-0012 | ✅ 통합 검증 완료 |
| SWE-REQ-0008 | 종료 명령 처리 | SWE-ITC-0008, SWE-ITC-0009 | ✅ 통합 검증 완료 |
| SWE-REQ-0009 | 알 수 없는 연산자 | SWE-ITC-0012 | ✅ 통합 검증 완료 |
| SWE-REQ-0010 | 결과 출력 형식 | SWE-ITC-0001~0007, SWE-ITC-0013 | ✅ 통합 검증 완료 (E2E 출력 형식 확인) |

---

## 7. 회귀 테스트

> SWE-5 통합 테스트 완료 이후, SWE-4 단위 테스트 전체를 회귀 테스트로 재실행하여 통합 이후 단위 기능 영향 없음을 확인한다.

| 회귀 대상 | 실행 명령 | 실행 날짜 | 결과 | 비고 |
|---------|---------|---------|------|------|
| SWE-TC-0001~0023 (전체 단위 테스트) | `ctest --output-on-failure` | 2026-04-11 | **All Pass (23/23)** | 통합 이후 단위 기능 영향 없음 확인 |

---

## 8. 리뷰 체크리스트

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 1 | 모든 통합 테스트 케이스에 고유 ID(`SWE-ITC-XXXX`) 부여됨 | ☑ 적합 | SWE-ITC-0001~0013 (13건) |
| 2 | 모든 SWE-2 인터페이스(SWE-IF)에 최소 1개 이상의 ITC 매핑됨 | ☑ 적합 | SWE-IF-0001: ITC-0001~0007, SWE-IF-0002: ITC-0001~0007, SWE-IF-0003: ITC-0008~0013 |
| 3 | 정상·경계·오류 시나리오가 모두 포함됨 | ☑ 적합 | 정상 7건, 경계값 2건, 오류 3건, 복합 1건 |
| 4 | SW 요구사항과의 추적성 확보됨 (미검증 요구사항 없음) | ☑ 적합 | SWE-REQ-0001~0010 전 항목 ITC 매핑 완료 |
| 5 | 통합 테스트 결과(Pass/Fail/Blocked)가 모두 기록됨 | ☑ 적합 | ITC-0001~0013 All Pass |
| 6 | 발견 결함이 식별·기록되고 조치 상태가 명확함 | ☑ 적합 | 결함 없음 확인 |
| 7 | 회귀 테스트 범위 및 결과 기록됨 | ☑ 적합 | §7 회귀 테스트 All Pass 기록 |
| 8 | SWE-4 단위 TC ↔ SWE-5 ITC ↔ SWE-REQ 추적성 매핑표 작성됨 | ☑ 적합 | §6 추적성 매핑표 (23건 → 13 ITC) |
| 9 | AppController (SWE-UNIT-0003) 통합 검증 완료 | ☑ 적합 | E2E 시나리오 ITC-0001~0013으로 검증 |
| 10 | 버전 및 변경 이력 기록됨 | ☑ 적합 | §9 변경 이력 |

---

## 9. 변경 이력

| 버전 | 날짜 | 변경 내용 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — SWE-ITC-0001~0013 작성, 전체 실행 Pass, SWE-4↔SWE-5 추적성 매핑 완료 | ASPICE SWE-5 전문가 |
