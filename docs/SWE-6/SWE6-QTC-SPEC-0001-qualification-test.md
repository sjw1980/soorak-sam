# SWE-6 소프트웨어 적격성 테스트 명세서

| 항목 | 내용 |
|------|------|
| 문서 ID | [SWE6-QTC-SPEC-0001](SWE6-QTC-SPEC-0001-qualification-test.md) |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-6 전문가 |
| 승인자 | — |
| 참조 문서 | [SWE1-REQ-SPEC-0001](../SWE-1/SWE-1-requirements.md) (SWE-1 요구사항), [SWE5-ITC-SPEC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md) (SWE-5 통합 검증), [SPL2-BUILD-0001](../SPL-2/SPL2-BUILD-0001-build-environment.md) (빌드 환경) |

---

## 1. 개요

### 1.1 목적

본 문서는 ASPICE SWE-6 소프트웨어 적격성 테스트 활동의 산출물이다.  
[SWE1-REQ-SPEC-0001](../SWE-1/SWE-1-requirements.md)에서 정의된 SW 요구사항([SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010)에 대한  
적격성 테스트 케이스(QTC), 테스트 실행 결과, 릴리스 기준 달성 현황 및 추적성 매핑표를 포함한다.

### 1.2 범위

| 검증 대상 | SW 요구사항 ID | 비고 |
|----------|-------------|------|
| 4칙 연산 기능 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0004 | Calculator 컴포넌트 — 단위·통합 검증 완료 |
| 0 나누기 예외 처리 | [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 비정상 종료 방지, 오류 메시지 출력 |
| CLI 입력 파싱 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | 유효 입력 형식 처리 |
| 반복 루프 및 오류 처리 | [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 잘못된 입력 후 루프 유지 |
| 종료 명령 처리 | [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | q / quit 명령 exit code 0 종료 |
| C++17 표준 준수 | [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) | 비기능 — 빌드 플래그 확인 |
| 커버리지 달성 | [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) | 비기능 — SWE-4 gcov 결과 참조 |

### 1.3 테스트 환경

| 항목 | 내용 |
|------|------|
| 빌드 시스템 | CMake 3.28.3 |
| 컴파일러 | GCC/G++ 13.3.0 (C++17) |
| 테스트 프레임워크 | Google Test v1.14.0 (E2E 적격성 검증 활용) |
| 실행 환경 | WSL Ubuntu 24.04 LTS |
| 빌드 타입 | Release (`-O2 -std=c++17`) |
| 테스트 실행 방식 | AppController E2E (stdin/stdout 리다이렉션, tests/integration/test_integration.cpp 인프라 활용) |
| 커버리지 도구 | gcov 13.3.0 / lcov (SWE-4 결과 참조) |

---

## 2. 적격성 테스트 계획

### 2.1 계획 요약

| 항목 | 내용 |
|------|------|
| 테스트 범위 | SW 요구사항([SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010) 전 항목 — 기능·비기능 포함 |
| 테스트 유형 | 블랙박스(Black-box) — CLI 입력·출력 기반 적격성 검증 |
| 진입 기준 | SWE-5 통합 테스트 All Pass ([SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001)~0013, 13/13 Pass) |
| 종료 기준 | 전체 QTC Pass율 100%, 미해결 Critical 결함 0건, SW 요구사항 커버리지 100% |
| 담당자 | ASPICE SWE-6 전문가 |
| 계획 일정 | 2026-04-11 (SWE-5 통합 검증 완료 직후) |

### 2.2 진입 기준 달성 현황

| 기준 항목 | 달성 여부 | 근거 |
|---------|---------|------|
| SWE-4 단위 테스트 All Pass (23/23) | ✅ 달성 | [SWE4-TC-SPEC-0001](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md) §3 실행 결과 참조 |
| SWE-5 통합 테스트 All Pass (13/13) | ✅ 달성 | [SWE5-ITC-SPEC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md) §4 실행 결과 참조 |
| 빌드 성공 (Release 타입) | ✅ 달성 | [SPL2-BUILD-0001](../SPL-2/SPL2-BUILD-0001-build-environment.md) 빌드 환경 참조 |
| SWE-3 단위 설계 승인 | ✅ 달성 | [SWE3-UNIT-SPEC-0001](../SWE-3/SWE3-UNIT-SPEC-0001-unit-design.md) 참조 |

---

## 3. 적격성 테스트 케이스 목록

> 적격성 테스트는 CLI 소프트웨어의 블랙박스 E2E 검증 방식으로 수행한다.  
> AppController를 통해 stdin 입력·stdout 출력을 검증하여 SW 요구사항 충족 여부를 직접 확인한다.

### 3.1 기능 적격성 테스트 — 4칙 연산 ([SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0004)

| ID | 테스트명 | SW 요구사항 ID | 시나리오 유형 | 입력 시퀀스 | 기대 결과 | 버전 | 날짜 |
|----|---------|-------------|------------|-----------|---------|------|------|
| <a id="SWE-QTC-0001"></a>[SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001) | 덧셈 연산 적격성 검증 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 정상 | `"3 + 5\nq\n"` | `"> Result: 8\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0002"></a>[SWE-QTC-0002](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0002) | 뺄셈 연산 적격성 검증 | [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002) | 정상 | `"10 - 3\nq\n"` | `"> Result: 7\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0003"></a>[SWE-QTC-0003](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0003) | 곱셈 연산 적격성 검증 | [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003) | 정상 | `"4 * 3\nq\n"` | `"> Result: 12\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0004"></a>[SWE-QTC-0004](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0004) | 나눗셈 연산 적격성 검증 | [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 정상 | `"10 / 2\nq\n"` | `"> Result: 5\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0005"></a>[SWE-QTC-0005](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0005) | 소수 나눗셈 결과 적격성 검증 | [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 경계값 | `"1 / 3\nq\n"` | `"> Result: 0.333333\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0006"></a>[SWE-QTC-0006](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0006) | 음수 피연산자 연산 적격성 검증 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 경계값 | `"-3 + -5\nq\n"` | `"> Result: -8\n> "` | v1.0 | 2026-04-11 |

### 3.2 기능 적격성 테스트 — 예외 처리 ([SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005), [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007))

| ID | 테스트명 | SW 요구사항 ID | 시나리오 유형 | 입력 시퀀스 | 기대 결과 | 버전 | 날짜 |
|----|---------|-------------|------------|-----------|---------|------|------|
| <a id="SWE-QTC-0007"></a>[SWE-QTC-0007](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0007) | 0 나누기 오류 메시지 적격성 검증 | [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 예외 | `"7 / 0\nq\n"` | `"> Error: Division by zero\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0008"></a>[SWE-QTC-0008](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0008) | 0 나누기 후 프로그램 정상 유지 적격성 검증 | [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 예외 | `"7 / 0\n3 + 1\nq\n"` | `"> Error: Division by zero\n> Result: 4\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0009"></a>[SWE-QTC-0009](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0009) | 잘못된 입력 후 루프 유지 적격성 검증 | [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 예외 | `"abc\n3 + 1\nq\n"` | Error: 포함, 이후 `Result: 4` 출력 | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0010"></a>[SWE-QTC-0010](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0010) | 빈 입력 처리 후 루프 유지 적격성 검증 | [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 예외 | `"\n3 + 2\nq\n"` | Error: 포함, 이후 `Result: 5` 출력 | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0011"></a>[SWE-QTC-0011](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0011) | 알 수 없는 연산자 처리 적격성 검증 | [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 예외 | `"3 % 5\nq\n"` | `Error: Unknown operator '%'` 포함 | v1.0 | 2026-04-11 |

### 3.3 기능 적격성 테스트 — CLI 인터페이스 및 루프 ([SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006)~0008)

| ID | 테스트명 | SW 요구사항 ID | 시나리오 유형 | 입력 시퀀스 | 기대 결과 | 버전 | 날짜 |
|----|---------|-------------|------------|-----------|---------|------|------|
| <a id="SWE-QTC-0012"></a>[SWE-QTC-0012](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0012) | CLI 소수 입력 파싱 적격성 검증 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | 경계값 | `"3.14 * 2.0\nq\n"` | `"> Result: 6.28\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0013"></a>[SWE-QTC-0013](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0013) | 다중 연산 반복 루프 적격성 검증 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006), [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 정상 | `"3 + 5\n10 / 2\n4 * 3\nq\n"` | `"> Result: 8\n> Result: 5\n> Result: 12\n> "` | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0014"></a>[SWE-QTC-0014](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0014) | q 명령 정상 종료 적격성 검증 | [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 정상 | `"q\n"` | `"> "` (exit code 0) | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0015"></a>[SWE-QTC-0015](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0015) | quit 명령 정상 종료 적격성 검증 | [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 정상 | `"quit\n"` | `"> "` (exit code 0) | v1.0 | 2026-04-11 |

### 3.4 비기능 적격성 테스트 ([SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009)~0010)

| ID | 테스트명 | SW 요구사항 ID | 시나리오 유형 | 검증 방법 | 기대 결과 | 버전 | 날짜 |
|----|---------|-------------|------------|---------|---------|------|------|
| <a id="SWE-QTC-0016"></a>[SWE-QTC-0016](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0016) | C++17 빌드 플래그 적격성 검증 | [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) | 비기능 | `CMakeLists.txt` `target_compile_features(calc_lib PUBLIC cxx_std_17)` 및 빌드 로그 확인 | `-std=c++17` 플래그 포함 빌드 성공 확인 | v1.0 | 2026-04-11 |
| <a id="SWE-QTC-0017"></a>[SWE-QTC-0017](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0017) | 단위 테스트 커버리지 100% 적격성 검증 | [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) | 비기능 | [SWE4-TC-SPEC-0001](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md) §4 gcov 결과 참조 | Statement Coverage 100%, Branch Coverage 100% 달성 확인 | v1.0 | 2026-04-11 |

---

## 4. 적격성 테스트 실행 결과

> 실행 날짜: 2026-04-11  
> 실행 환경: WSL Ubuntu 24.04 LTS, GCC/G++ 13.3.0, GTest v1.14.0  
> 실행 기반: SWE-5 통합 테스트 인프라(tests/integration/test_integration.cpp) QTC 매핑 실행  
>            비기능 항목(QTC-0016~0017)은 빌드 로그 및 SWE-4 커버리지 결과 정적 확인

### 4.1 최종 요약

```
전체 적격성 테스트 케이스: 17건
결과: 17/17 Pass (Pass율 100%)
미해결 Critical 결함: 0건
SW 요구사항 커버리지: SWE-REQ-0001~0010 100%
```

### 4.2 QTC별 실행 결과

| QTC ID | 테스트명 | 실행 날짜 | 담당자 | 결과 | 실제 결과 요약 | 연결 결함 ID | 비고 |
|--------|---------|---------|--------|------|------------|-----------|------|
| [SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001) | 덧셈 연산 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 8\n> "` 일치 확인 ([SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001) 대응) | — | |
| [SWE-QTC-0002](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0002) | 뺄셈 연산 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 7\n> "` 일치 확인 ([SWE-ITC-0002](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0002) 대응) | — | |
| [SWE-QTC-0003](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0003) | 곱셈 연산 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 12\n> "` 일치 확인 ([SWE-ITC-0003](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0003) 대응) | — | |
| [SWE-QTC-0004](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0004) | 나눗셈 연산 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 5\n> "` 일치 확인 ([SWE-ITC-0004](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0004) 대응) | — | |
| [SWE-QTC-0005](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0005) | 소수 나눗셈 결과 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 0.333333\n> "` double 기본 출력 형식 확인 | — | [SWE-TC-0007](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md#SWE-TC-0007) 기반 |
| [SWE-QTC-0006](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0006) | 음수 피연산자 연산 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: -8\n> "` 일치 확인 ([SWE-ITC-0007](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0007) 대응) | — | |
| [SWE-QTC-0007](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0007) | 0 나누기 오류 메시지 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Error: Division by zero\n> "` 일치 확인 ([SWE-ITC-0005](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0005) 대응) | — | |
| [SWE-QTC-0008](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0008) | 0 나누기 후 프로그램 정상 유지 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | 오류 후 `Result: 4` 출력, 프로그램 정상 유지 확인 | — | [SWE-ITC-0005](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0005)+0001 복합 |
| [SWE-QTC-0009](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0009) | 잘못된 입력 후 루프 유지 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `Error: Invalid input format...` 후 `Result: 4` 출력 확인 ([SWE-ITC-0010](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0010) 대응) | — | |
| [SWE-QTC-0010](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0010) | 빈 입력 처리 후 루프 유지 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `Error: Invalid input format...` 후 `Result: 5` 출력 확인 ([SWE-ITC-0011](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0011) 대응) | — | |
| [SWE-QTC-0011](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0011) | 알 수 없는 연산자 처리 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `Error: Unknown operator '%'...` 포함 확인 ([SWE-ITC-0012](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0012) 대응) | — | |
| [SWE-QTC-0012](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0012) | CLI 소수 입력 파싱 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 6.28\n> "` 일치 확인 ([SWE-ITC-0006](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0006) 기반) | — | |
| [SWE-QTC-0013](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0013) | 다중 연산 반복 루프 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `"> Result: 8\n> Result: 5\n> Result: 12\n> "` 일치 확인 ([SWE-ITC-0013](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0013) 확장) | — | |
| [SWE-QTC-0014](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0014) | q 명령 정상 종료 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | output=`"> "`, exitCode=0 확인 ([SWE-ITC-0008](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0008) 대응) | — | |
| [SWE-QTC-0015](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0015) | quit 명령 정상 종료 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | output=`"> "`, exitCode=0 확인 ([SWE-ITC-0009](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0009) 대응) | — | |
| [SWE-QTC-0016](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0016) | C++17 빌드 플래그 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | `CMakeLists.txt` `cxx_std_17` 확인, 빌드 성공 — [SPL2-BUILD-0001](../SPL-2/SPL2-BUILD-0001-build-environment.md) 참조 | — | 정적 확인 |
| [SWE-QTC-0017](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0017) | 단위 테스트 커버리지 100% 적격성 검증 | 2026-04-11 | ASPICE SWE-6 전문가 | **Pass** | Calculator/InputParser: Statement 100%, Branch 100% — [SWE4-TC-SPEC-0001](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md) §4 참조 | — | 정적 확인 |

---

## 5. 결함 목록 (SWE-6 신규 발견)

> 본 적격성 테스트 실행(2026-04-11) 결과: 신규 Critical/Major 결함 없음.  
> SWE-4에서 식별된 SWE-DEF-0001 (Calculator 구문 커버리지 미달)은 SWE-4 §5에서 해소됨을 확인.

| ID | 발견 QTC ID | 심각도 | 재현 조건 | 상태 | 조치 내용 | 날짜 |
|----|-----------|--------|---------|------|---------|------|
| — | — | — | — | — | 신규 결함 없음 | 2026-04-11 |

---

## 6. 추적성 매핑표 (SWE-1 → SWE-6)

| SW 요구사항 ID | 요구사항 요약 | 적격성 QTC ID | 통합 ITC ID | QTC 결과 | 비고 |
|-------------|-----------|-------------|-----------|---------|------|
| [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 덧셈 연산 | [SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001), [SWE-QTC-0006](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0006) | [SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001), [SWE-ITC-0007](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0007) | **Pass** | 정상 + 음수 경계값 |
| [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002) | 뺄셈 연산 | [SWE-QTC-0002](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0002) | [SWE-ITC-0002](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0002) | **Pass** | |
| [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003) | 곱셈 연산 | [SWE-QTC-0003](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0003) | [SWE-ITC-0003](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0003) | **Pass** | |
| [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 나눗셈 연산 | [SWE-QTC-0004](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0004), [SWE-QTC-0005](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0005) | [SWE-ITC-0004](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0004), [SWE-ITC-0006](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0006) | **Pass** | 정수 + 소수 결과 |
| [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 0 나누기 예외 처리 | [SWE-QTC-0007](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0007), [SWE-QTC-0008](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0008) | [SWE-ITC-0005](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0005) | **Pass** | 오류 메시지 + 정상 유지 |
| [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | CLI 입력 파싱 | [SWE-QTC-0012](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0012), [SWE-QTC-0013](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0013) | [SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001)~0007, [SWE-ITC-0013](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0013) | **Pass** | 소수·다중 입력 |
| [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 반복 루프 및 오류 처리 | [SWE-QTC-0009](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0009), [SWE-QTC-0010](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0010), [SWE-QTC-0011](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0011), [SWE-QTC-0013](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0013) | [SWE-ITC-0010](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0010)~0013 | **Pass** | 잘못된 입력 후 루프 유지 |
| [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 종료 명령 처리 | [SWE-QTC-0014](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0014), [SWE-QTC-0015](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0015) | [SWE-ITC-0008](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0008), [SWE-ITC-0009](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0009) | **Pass** | q / quit exit code 0 |
| [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) | C++17 표준 준수 | [SWE-QTC-0016](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0016) | — | **Pass** | 빌드 플래그 정적 확인 |
| [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) | 단위 커버리지 100% | [SWE-QTC-0017](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0017) | — | **Pass** | SWE-4 gcov 결과 참조 |

### 6.1 SW 요구사항별 적격성 검증 현황

| SWE-REQ ID | 요구사항 요약 | QTC 수 | 적격성 검증 상태 |
|-----------|-----------|-------|--------------|
| [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 덧셈 기능 | 2건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002) | 뺄셈 기능 | 1건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003) | 곱셈 기능 | 1건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 나눗셈 기능 | 2건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 0 나누기 예외 처리 | 2건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | CLI 입력 파싱 | 2건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 반복 루프 및 오류 처리 | 4건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 종료 명령 처리 | 2건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) | C++17 표준 준수 | 1건 | ✅ 적격성 검증 완료 |
| [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) | 단위 커버리지 100% | 1건 | ✅ 적격성 검증 완료 |

---

## 7. 릴리스 기준 달성 현황 (Exit Criteria)

| 기준 항목 | 목표 | 달성값 | 달성 여부 | 비고 |
|---------|------|--------|---------|------|
| 전체 QTC Pass율 | 100% | 100% (17/17) | ✅ 달성 | [SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001)~0017 전 항목 Pass |
| 미해결 Critical 결함 | 0건 | 0건 | ✅ 달성 | SWE-6 신규 발견 결함 없음 |
| SW 요구사항 커버리지 | 100% | 100% (10/10) | ✅ 달성 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010 전 항목 QTC 매핑 완료 |
| 회귀 테스트 Pass율 | 100% | 100% (36/36) | ✅ 달성 | §8 회귀 테스트 결과 참조 |
| 미해결 Major 이상 결함 | 0건 | 0건 | ✅ 달성 | SWE-4 SWE-DEF-0001 해소 확인 |

> **릴리스 기준 판정**: 전 항목 달성 — **릴리스 승인 가능** (승인자 날인 후 확정)

---

## 8. 회귀 테스트

> 적격성 테스트 실행 이후, SWE-4 단위 + SWE-5 통합 테스트 전체를 회귀 테스트로 재실행하여  
> 적격성 검증 과정에서 기존 기능 영향이 없음을 확인한다.

| 회귀 대상 | 실행 명령 | 실행 날짜 | 결과 | 비고 |
|---------|---------|---------|------|------|
| [SWE-TC-0001](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md#SWE-TC-0001)~0023 (단위 전체) | `ctest --output-on-failure -v` | 2026-04-11 | **All Pass (23/23)** | 단위 기능 회귀 영향 없음 |
| [SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001)~0013 (통합 전체) | `ctest --output-on-failure -v` | 2026-04-11 | **All Pass (13/13)** | 통합 기능 회귀 영향 없음 |
| 전체 (단위+통합 36건) | `ctest --output-on-failure -v` | 2026-04-11 | **All Pass (36/36), 5.34 sec** | SWE-5 회귀 결과 재확인 ([SWE5-ITC-SPEC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md) §7 참조) |

---

## 9. 리뷰 체크리스트

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 1 | 모든 적격성 테스트 케이스에 고유 ID(`SWE-QTC-XXXX`) 부여됨 | ☑ 적합 | [SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001)~0017 (17건) |
| 2 | 모든 SW 요구사항([SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010)에 최소 1개 이상의 QTC 매핑됨 | ☑ 적합 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010 전 항목 매핑 완료 |
| 3 | 정상·경계·예외·비기능 시나리오가 모두 포함됨 | ☑ 적합 | 정상 7건, 경계값 4건, 예외 4건, 비기능 2건 |
| 4 | 테스트 결과(Pass/Fail/Blocked)가 모두 기록됨 | ☑ 적합 | QTC-0001~0017 All Pass |
| 5 | 발견 결함이 식별·기록되고 조치 상태가 명확함 | ☑ 적합 | 신규 결함 없음 확인 |
| 6 | 릴리스 기준(Exit Criteria) 전 항목 달성 여부 확인됨 | ☑ 적합 | §7 전 항목 ✅ 달성 |
| 7 | 회귀 테스트 범위 및 결과 기록됨 | ☑ 적합 | §8 회귀 테스트 36/36 All Pass |
| 8 | SWE-REQ ↔ SWE-QTC ↔ SWE-ITC 추적성 매핑표 작성됨 | ☑ 적합 | §6 추적성 매핑표 (10 REQ → 17 QTC) |
| 9 | 비기능 요구사항(C++17, 커버리지) 검증 기록됨 | ☑ 적합 | [SWE-QTC-0016](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0016)~0017 Pass 확인 |
| 10 | 버전 및 변경 이력 기록됨 | ☑ 적합 | §10 변경 이력 참조 |

---

## 10. 변경 이력

| 버전 | 날짜 | 변경 내용 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — [SWE-QTC-0001](SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001)~0017 작성, SWE-REQ↔QTC↔ITC 추적성 매핑 완료, 릴리스 기준 전 항목 달성 확인 | ASPICE SWE-6 전문가 |
