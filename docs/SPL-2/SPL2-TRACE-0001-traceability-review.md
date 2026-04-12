# SPL-2 추적성 매핑표 및 리뷰 체크리스트

| 항목 | 내용 |
|------|------|
| 문서 ID | [SPL2-TRACE-0001](SPL2-TRACE-0001-traceability-review.md) |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-05 |
| 상태 | Draft |
| 작성자 | ASPICE SPL-2 전문가 |
| 승인자 | — |

---

## 1. 추적성 매핑표 (상위 산출물 → SPL-2 산출물)

### 1.1 SWE 요구사항 → SPL-2 피처 매핑

| SWE 요구사항 ID | 요구사항 요약 | SPL-2 피처 ID | 피처명 | 관계 | 상태 |
|--------------|------------|-------------|------|------|------|
| [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001) | 덧셈 연산 | [SPL2-FEAT-0001](SPL2-FEAT-0001-feature-model.md) | 덧셈 연산 (Addition) | 구현 | Approved |
| [SWE-REQ-0002](../SWE-1/SWE-1-requirements.md#SWE-REQ-0002) | 뺄셈 연산 | SPL2-FEAT-0002 | 뺄셈 연산 (Subtraction) | 구현 | Approved |
| [SWE-REQ-0003](../SWE-1/SWE-1-requirements.md#SWE-REQ-0003) | 곱셈 연산 | SPL2-FEAT-0003 | 곱셈 연산 (Multiplication) | 구현 | Approved |
| [SWE-REQ-0004](../SWE-1/SWE-1-requirements.md#SWE-REQ-0004) | 나눗셈 연산 | SPL2-FEAT-0004 | 나눗셈 연산 (Division) | 구현 | Approved |
| [SWE-REQ-0005](../SWE-1/SWE-1-requirements.md#SWE-REQ-0005) | 0 나누기 예외 처리 | SPL2-FEAT-0005 | 0 나누기 예외 처리 | 구현 | Approved |
| [SWE-REQ-0006](../SWE-1/SWE-1-requirements.md#SWE-REQ-0006) | CLI 사용자 인터페이스 | SPL2-FEAT-0006 | CLI 사용자 인터페이스 | 구현 | Approved |
| [SWE-REQ-0007](../SWE-1/SWE-1-requirements.md#SWE-REQ-0007) | 반복 입력 루프 | SPL2-FEAT-0007 | 반복 입력 루프 | 구현 | Approved |
| [SWE-REQ-0008](../SWE-1/SWE-1-requirements.md#SWE-REQ-0008) | 종료 명령 처리 | SPL2-FEAT-0008 | 종료 명령 처리 | 구현 | Approved |

### 1.2 SWE 산출물 → SPL-2 빌드 활동 매핑

| 참조 ID | 유형 | SPL-2 빌드 활동 ID | 관계 | 상태 | 비고 |
|---------|------|------------------|------|------|------|
| [SWE-COMP-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0001) (calc_lib) | 컴포넌트 | SPL2-BUILD-0002 | calc_lib 빌드 대상 | Draft | SWE-3 산출물 연계 |
| [SWE-COMP-0002](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-COMP-0002) (cli) | 컴포넌트 | SPL2-BUILD-0003 | CLI 실행 파일 빌드 대상 | Draft | SWE-3 산출물 연계 |
| [SWE-IF-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0001)~0004 | 인터페이스 | SPL2-BUILD-0004 | 전체 빌드 시 인터페이스 연결 검증 | Draft | SWE-5 통합 테스트 선행 |
| SWE-TC-XXXX | 단위 테스트 케이스 | SPL2-BUILD-0005, 0006 | 단위 테스트 빌드 및 실행 | Open | SWE-4 완료 후 갱신 |
| SWE-ITC-XXXX | 통합 테스트 케이스 | SPL2-BUILD-0003 | CLI 통합 테스트 대상 바이너리 | Open | SWE-5 완료 후 갱신 |
| SWE-QTC-XXXX | 적격성 테스트 케이스 | SPL2-BUILD-0010 | Release 바이너리 적격성 검증 | Open | SWE-6 완료 후 갱신 |

### 1.3 SPL-2 산출물 → 출시 노트 매핑

| SPL-2 산출물 ID | 유형 | 출시 노트 참조 | 관계 | 상태 |
|---------------|------|-------------|------|------|
| [SPL2-FEAT-0001](SPL2-FEAT-0001-feature-model.md)~0012 | 피처 모델 | [SPL2-REL-0001](SPL2-REL-0001-release-note.md) §5 | 검증 결과 대상 피처 | Draft |
| [SPL2-BUILD-0001](SPL2-BUILD-0001-build-environment.md)~0010 | 빌드 활동 | [SPL2-REL-0001](SPL2-REL-0001-release-note.md) §1 | 릴리스 대상 빌드 절차 | Draft |
| SUP8-CI-XXXX | 형상 항목 | [SPL2-REL-0001](SPL2-REL-0001-release-note.md) §1 | 릴리스 형상 항목 | Open |
| SUP8-BL-0001 | 베이스라인 | [SPL2-REL-0001](SPL2-REL-0001-release-note.md) §1 | 릴리스 베이스라인 | Open |

---

## 2. SPL-2 리뷰 체크리스트

### 2.1 피처 모델 ([SPL2-FEAT-0001](SPL2-FEAT-0001-feature-model.md)) 검토

| 번호 | 체크 항목 | 결과 | 비고 |
|------|---------|------|------|
| 1 | 모든 피처에 고유 ID(`SPL2-FEAT-XXXX`) 부여됨 | ☑ | FEAT-0001~0012 부여 완료 |
| 2 | 공통(Common) / 가변(Variable) 피처가 명확히 구분됨 | ☑ | 공통 8개, 가변 4개 |
| 3 | 모든 SWE 요구사항([SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0008)이 피처와 연결됨 | ☑ | 1:1 매핑 완료 |
| 4 | 피처 간 의존성이 명시됨 | ☑ | §4 의존성 기술 완료 |
| 5 | 가변 피처의 빌드 플래그/설정이 명시됨 | ☑ | FEAT-0009~0012 플래그 명시 |
| 6 | 버전 및 날짜 기록됨 | ☑ | v1.0 / 2026-04-05 |

### 2.2 빌드 환경 및 활동 ([SPL2-BUILD-0001](SPL2-BUILD-0001-build-environment.md)) 검토

| 번호 | 체크 항목 | 결과 | 비고 |
|------|---------|------|------|
| 7 | 툴체인(컴파일러 버전 포함) 완전히 정의됨 | ☑ | g++ 13.x, CMake 3.16+, GTest 1.14.x |
| 8 | 운영체제 버전이 명시됨 | ☑ | Ubuntu 22.04 LTS (x86_64) |
| 9 | 빌드 타입별(Debug/Release) 컴파일 플래그 명시됨 | ☑ | §1.4 플래그 표 완료 |
| 10 | 빌드 활동의 순서 및 산출물이 명세됨 | ☑ | BUILD-0001~0010 정의 완료 |
| 11 | 공통 빌드 단계와 가변 빌드 단계가 구분됨 | ☑ | §2.1~2.3 분류 완료 |
| 12 | 빌드 재현성 기준(버전 고정 포함)이 문서화됨 | ☑ | §3 재현성 기준 정의 |
| 13 | SWE 프로세스(SWE-3/4/5/6)와의 연계가 명시됨 | ☑ | §4 연계 표 완료 |

### 2.3 출시 노트 ([SPL2-REL-0001](SPL2-REL-0001-release-note.md)) 검토

| 번호 | 체크 항목 | 결과 | 비고 |
|------|---------|------|------|
| 14 | 출시 노트 헤더(버전, 날짜, 담당자, 승인자) 포함됨 | ☑ | Draft — 승인자 미확정 |
| 15 | 포함된 변경 사항(CR ID 참조)이 기술됨 | ☐ | SUP-10 CR ID 미확정 (SWE-4~6 완료 후 갱신) |
| 16 | 해결된 결함 목록(SWE-DEF / SUP9-PR ID 참조)이 기술됨 | ☐ | SWE-4 완료 후 갱신 |
| 17 | 알려진 제한 사항 및 미해결 결함이 명시됨 | ☑ | §4 미완료 항목 명시 |
| 18 | 검증 결과(SWE-QTC 통과 여부) 요약이 포함됨 | ☐ | SWE-6 완료 후 갱신 |
| 19 | 릴리스 판정 기준이 명시됨 | ☑ | §6 판정 기준 6개 항목 정의 |
| 20 | 출시 노트가 근거 없이 "PASS" 처리되지 않음 | ☑ | 미수행 항목은 "—" 표시 |

### 2.4 추적성 검토

| 번호 | 체크 항목 | 결과 | 비고 |
|------|---------|------|------|
| 21 | SWE-REQ ↔ SPL2-FEAT 추적성 100% 확보 | ☑ | 8개 요구사항 전체 매핑 |
| 22 | SWE 컴포넌트 ↔ SPL2-BUILD 추적성 확보 | ☑ | calc_lib, cli 연계 |
| 23 | SWE-TC/ITC/QTC ↔ SPL2-BUILD 추적성 확보 | ☐ | SWE-4/5/6 완료 후 갱신 |
| 24 | SPL2 산출물 ↔ 출시 노트 추적성 확보 | ☑ | §1.3 매핑 완료 |

---

## 3. 리뷰 결과 요약

| 항목 | 총 체크 수 | 충족(☑) | 미충족(☐) | 미해당(N/A) |
|------|---------|--------|---------|-----------|
| 피처 모델 | 6 | 6 | 0 | 0 |
| 빌드 환경/활동 | 7 | 7 | 0 | 0 |
| 출시 노트 | 7 | 4 | 3 | 0 |
| 추적성 | 4 | 3 | 1 | 0 |
| **합계** | **24** | **20** | **4** | **0** |

> **미충족 항목 조치 계획**: SWE-4~6 전문가 에이전트 수행 완료 후 CR ID, 결함 목록, 검증 결과, TC 추적성을 갱신하여 체크리스트 전 항목 충족 상태로 갱신한다.

---

## 4. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-05 | 최초 작성 — 추적성 매핑표 및 리뷰 체크리스트 작성 | ASPICE SPL-2 전문가 |
