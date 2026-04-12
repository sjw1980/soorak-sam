# SWE-3 추적성 매핑표 및 리뷰 체크리스트

| 항목 | 내용 |
|------|------|
| 문서 ID | [SWE3-TRACE-0001](SWE3-TRACE-0001-traceability-review.md) |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-3 전문가 |
| 승인자 | — |
| 참조 문서 | [SWE1-REQ-SPEC-0001](../SWE-1/SWE-1-requirements.md), [SWE2-ARCH-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md), [SWE2-TRACE-0001](../SWE-2/SWE2-TRACE-0001-traceability-review.md), [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) |

---

## 1. SWE-2 → SWE-3 추적성 매핑표

### 1.1 컴포넌트 ↔ 단위 매핑

| 컴포넌트 ID | 컴포넌트명 | 단위 ID | 단위명 | 상태 | 비고 |
|-----------|-----------|--------|--------|------|------|
| [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | Calculator | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | Calculator | Covered | 1:1 매핑 — 연산 수행 전담 클래스 |
| [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) | InputParser | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) | InputParser | Covered | 1:1 매핑 — 입력 파싱 전담 클래스 |
| [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) | AppController | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | AppController | Covered | 1:1 매핑 — 메인 루프 제어 클래스 |
| [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001), [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) | (공통) | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) | Types | Covered | 공통 데이터 타입 — OperationResult, ParsedInput, InputType |

### 1.2 미할당 컴포넌트 확인

| 확인 항목 | 결과 |
|---------|------|
| 미할당 컴포넌트 (단위 없음) | 없음 — 전체 3개 컴포넌트 모두 단위에 매핑됨 |
| 미연결 단위 (컴포넌트 없음) | 없음 — 전체 4개 단위가 컴포넌트에 연결됨 |

---

## 2. SW 요구사항 → SWE-3 단위 추적성 매핑표

| SW 요구사항 ID | 요구사항 제목 | 컴포넌트 ID | 단위 ID | 관련 함수 | 상태 | 비고 |
|---------------|------------|-----------|--------|---------|------|------|
| [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 덧셈 연산 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | `calculate(a, '+', b)` | Covered | op='+' 분기 |
| [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002) | 뺄셈 연산 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | `calculate(a, '-', b)` | Covered | op='-' 분기 |
| [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003) | 곱셈 연산 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | `calculate(a, '*', b)` | Covered | op='*' 분기 |
| [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 나눗셈 연산 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | `calculate(a, '/', b)` (b≠0) | Covered | op='/', b≠0 분기 |
| [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 0 나누기 예외 처리 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) | `calculate(a, '/', 0)` | Covered | success=false, errorMsg 반환 |
| [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | CLI 사용자 인터페이스 | [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002), [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002), [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | `parse(line)`, `run()` | Covered | InputParser가 파싱, AppController가 출력 |
| [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 반복 입력 루프 | [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | `run()` while 루프 | Covered | QUIT/EOF 전까지 반복 |
| [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 종료 명령 처리 | [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002), [SWE-COMP-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0003) | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002), [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) | `isQuitCommand()`, `run()` | Covered | QUIT 감지 시 run() return 0 |
| [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) | C++17 준수 | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001)~0003 | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001)~0004 | 전체 | Covered | 모든 단위 `-std=c++17` 빌드 대상 |
| [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) | 커버리지 100% | [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001), [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001), [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) | `calculate()`, `parse()` | Covered | 독립 클래스 구조로 단위 테스트 100% 커버리지 달성 가능 |

### 2.1 미할당 요구사항 확인

| 확인 항목 | 결과 |
|---------|------|
| 미할당 요구사항 (단위 없음) | 없음 — 전체 10개 요구사항 모두 단위에 매핑됨 |
| 커버리지 대상 요구사항 추적 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0005, [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) → [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001), [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) 단위 테스트로 검증 예정 |

---

## 3. 인터페이스 ↔ 단위 함수 매핑

| 인터페이스 ID | 인터페이스명 | 제공 단위 ID | 소비 단위 ID | 구현 함수 | 상태 |
|-------------|-----------|-----------|-----------|---------|------|
| [SWE-IF-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0001) | OperationRequest | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) (파라미터 공급) | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) (수신) | `Calculator::calculate(a, op, b)` 호출 파라미터 | Covered |
| [SWE-IF-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0002) | OperationResult | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001) (반환) | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) (수신) | `Calculator::calculate()` 반환값 `OperationResult` | Covered |
| [SWE-IF-0003](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0003) | ParsedInput | [SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002) (반환) | [SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003) (수신) | `InputParser::parse()` 반환값 `ParsedInput` | Covered |

---

## 4. 단위 설계 리뷰 체크리스트

### 4.1 단위 식별 및 ID 체계

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 1 | 모든 단위에 고유 ID가 부여됨 (`SWE-UNIT-XXXX` 형식) | ☑ Pass | [SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001)~0004 |
| 2 | 모든 단위가 상위 SWE-2 컴포넌트(SWE-COMP-XXXX)와 매핑됨 | ☑ Pass | [SWE3-TRACE-0001](SWE3-TRACE-0001-traceability-review.md) §1.1 참조 |
| 3 | 단위 ID의 중복 없음 | ☑ Pass | 0001~0004 순차 부여 |
| 4 | 기존 컴포넌트 ID·요구사항 ID가 임의 변경·삭제되지 않음 | ☑ Pass | SWE-COMP, SWE-REQ, SWE-IF ID 원본 유지 |

### 4.2 단위 인터페이스 완전성

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 5 | 모든 공개(public) 함수의 시그니처가 정의됨 | ☑ Pass | calculate(), parse(), run() |
| 6 | 모든 공개 함수의 입력 파라미터 및 타입이 명세됨 | ☑ Pass | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) §4 참조 |
| 7 | 모든 공개 함수의 출력/반환값 및 타입이 명세됨 | ☑ Pass | OperationResult, ParsedInput, int 명세 |
| 8 | 모든 공개 함수의 사전 조건(Pre-condition)이 명세됨 | ☑ Pass | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) §4.x.3 참조 |
| 9 | 모든 공개 함수의 사후 조건(Post-condition)이 명세됨 | ☑ Pass | 성공/실패 각 케이스 정의됨 |
| 10 | 내부(private) 보조 함수도 역할 및 시그니처가 기술됨 | ☑ Pass | trim(), isQuitCommand(), printResult(), printError(), printPrompt() |

### 4.3 SW 요구사항 추적성 검증

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 11 | 모든 SW 요구사항이 최소 1개 이상의 단위에 매핑됨 | ☑ Pass | 10/10 요구사항 커버 |
| 12 | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0004 (4칙 연산)가 Calculator([SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001))에 매핑됨 | ☑ Pass | calculate() 함수 분기별 처리 |
| 13 | [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) (0 나누기 예외)가 Calculator([SWE-UNIT-0001](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0001))에 매핑됨 | ☑ Pass | b==0 판정 및 오류 반환 명세 |
| 14 | [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) (CLI 인터페이스)가 InputParser([SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002)) 및 AppController([SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003))에 매핑됨 | ☑ Pass | parse(), run() 명세 |
| 15 | [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) (반복 루프)가 AppController([SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003))에 매핑됨 | ☑ Pass | run() while 루프 알고리즘 명세 |
| 16 | [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) (종료 명령)가 InputParser([SWE-UNIT-0002](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0002)) 및 AppController([SWE-UNIT-0003](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0003))에 매핑됨 | ☑ Pass | isQuitCommand(), QUIT 처리 알고리즘 |
| 17 | [SWE-REQ-0009](../SWE-1/SWE-1-requirements.md#SWE-REQ-0009) (C++17)가 모든 단위에 반영됨 | ☑ Pass | 코딩 규칙 §7 및 파일 구조 #5 참조 |
| 18 | [SWE-REQ-0010](../SWE-1/SWE-1-requirements.md#SWE-REQ-0010) (커버리지 100%)가 단위 구조에 반영됨 | ☑ Pass | Calculator, InputParser 독립 클래스 — 단위 테스트 가능 구조 |

### 4.4 단위 설계 품질

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 19 | 각 단위가 단일 책임 원칙(SRP)에 부합함 | ☑ Pass | Calculator(연산), InputParser(파싱), AppController(제어), Types(타입정의) |
| 20 | 단위 간 의존성이 명확히 정의됨 | ☑ Pass | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) §6 의존성 표 참조 |
| 21 | 내부 로직(알고리즘)이 의사 코드 또는 판정 표로 기술됨 | ☑ Pass | §4.1.4, §4.2.4, §4.3.4 알고리즘 및 판정 표 |
| 22 | 공통 데이터 타입이 별도 헤더(types.h)에 분리 정의됨 | ☑ Pass | [SWE-UNIT-0004](SWE3-UNIT-SPEC-0001-unit-design.md#SWE-UNIT-0004) (types.h) |
| 23 | 예외 처리 방식이 반환값 기반으로 일관성 있게 정의됨 | ☑ Pass | OperationResult.success, ParsedInput.type으로 오류 전달 (C++ 예외 미사용) |
| 24 | 파일 구조가 단위별로 .h/.cpp 쌍으로 정의됨 | ☑ Pass | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) §5 파일 구조 참조 |
| 25 | 버전(v1.0) 및 날짜(2026-04-11)가 문서에 기록됨 | ☑ Pass | 문서 헤더 및 §8 변경 이력 |
| 26 | 출력 형식(Result:, Error: 등)이 명세됨 | ☑ Pass | [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) §4.3.5 출력 형식 명세 |

---

## 5. 리뷰 결과 요약

| 분류 | Pass | Fail | N/A |
|------|------|------|-----|
| 단위 식별 및 ID 체계 (1~4) | 4 | 0 | 0 |
| 단위 인터페이스 완전성 (5~10) | 6 | 0 | 0 |
| SW 요구사항 추적성 검증 (11~18) | 8 | 0 | 0 |
| 단위 설계 품질 (19~26) | 8 | 0 | 0 |
| **합계** | **26** | **0** | **0** |

> **리뷰 결론**: 전체 26개 체크 항목 Pass. [SWE3-UNIT-SPEC-0001](SWE3-UNIT-SPEC-0001-unit-design.md) 문서는 Approved 조건을 충족함.

---

## 6. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — SWE-2↔SWE-3 추적성 매핑, SW 요구사항↔단위 추적성 매핑, 26개 리뷰 항목 검토 완료 | ASPICE SWE-3 전문가 |
