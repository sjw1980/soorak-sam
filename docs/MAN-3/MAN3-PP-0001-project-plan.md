# MAN-3 프로젝트 계획서 (Project Plan)

| 항목            | 내용                                         |
| --------------- | -------------------------------------------- |
| 문서 ID         | [MAN3-PP-0001](MAN3-PP-0001-project-plan.md) |
| 프로젝트명      | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6   |
| 버전            | v1.1 / 2026-04-12                            |
| 상태            | Draft                                        |
| 프로젝트 관리자 | —                                            |
| 승인자          | —                                            |

---

## 1. 프로젝트 개요

### 1.1 목적

C++ CLI 기반 4칙 연산 계산기 소프트웨어를 ASPICE PAM 3.1 SWE-1~SWE-6 프로세스에 따라 개발·검증한다.

### 1.2 범위

| 포함                          | 제외             |
| ----------------------------- | ---------------- |
| SWE-1 요구사항 분석           | HW 설계          |
| SWE-2 아키텍처 설계           | 외부 시스템 연동 |
| SWE-3 상세 설계               | 배포 인프라 구성 |
| SWE-4 단위 검증 (Google Test) |                  |
| SWE-5 통합 테스트             |                  |
| SWE-6 적격성 테스트           |                  |

### 1.3 완료 기준

- 모든 SWE-REQ 요구사항이 SWE-QTC 테스트 케이스에 의해 검증됨
- 단위 커버리지(문장 100%, 분기 100%) 달성
- 모든 SWE-6 적격성 테스트 Pass
- 산출물 버전 Approved 상태

---

## 2. WBS (Work Breakdown Structure)

| ID                                                                                    | 작업명                                  | 상위 항목                                                   | 담당 에이전트       | 계획 시작  | 계획 완료  | 실제 완료  | 진행률 | 상태   |
| ------------------------------------------------------------------------------------- | --------------------------------------- | ----------------------------------------------------------- | ------------------- | ---------- | ---------- | ---------- | ------ | ------ |
| <a id="MAN3-WBS-0001"></a>[MAN3-WBS-0001](MAN3-PP-0001-project-plan.md#MAN3-WBS-0001) | SWE-1 소프트웨어 요구사항 분석          | —                                                           | ASPICE SWE-1 전문가 | 2026-04-05 | 2026-04-05 | 2026-04-05 | 100%   | Closed |
| <a id="MAN3-WBS-0002"></a>[MAN3-WBS-0002](MAN3-PP-0001-project-plan.md#MAN3-WBS-0002) | SWE-2 소프트웨어 아키텍처 설계          | —                                                           | ASPICE SWE-2 전문가 | 2026-04-05 | 2026-04-05 | 2026-04-05 | 100%   | Closed |
| <a id="MAN3-WBS-0003"></a>[MAN3-WBS-0003](MAN3-PP-0001-project-plan.md#MAN3-WBS-0003) | SWE-3 소프트웨어 상세 설계              | —                                                           | ASPICE SWE-3 전문가 | 2026-04-05 | 2026-04-05 | 2026-04-05 | 100%   | Closed |
| <a id="MAN3-WBS-0004"></a>[MAN3-WBS-0004](MAN3-PP-0001-project-plan.md#MAN3-WBS-0004) | SWE-3 소스코드 구현                     | [MAN3-WBS-0003](MAN3-PP-0001-project-plan.md#MAN3-WBS-0003) | ASPICE SWE-3 전문가 | 2026-04-05 | 2026-04-05 | 2026-04-05 | 100%   | Closed |
| <a id="MAN3-WBS-0005"></a>[MAN3-WBS-0005](MAN3-PP-0001-project-plan.md#MAN3-WBS-0005) | SWE-4 단위 테스트 케이스 작성           | —                                                           | ASPICE SWE-4 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |
| <a id="MAN3-WBS-0006"></a>[MAN3-WBS-0006](MAN3-PP-0001-project-plan.md#MAN3-WBS-0006) | SWE-4 단위 테스트 실행 및 커버리지 분석 | [MAN3-WBS-0005](MAN3-PP-0001-project-plan.md#MAN3-WBS-0005) | ASPICE SWE-4 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |
| <a id="MAN3-WBS-0007"></a>[MAN3-WBS-0007](MAN3-PP-0001-project-plan.md#MAN3-WBS-0007) | SWE-5 통합 테스트 케이스 작성           | —                                                           | ASPICE SWE-5 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |
| <a id="MAN3-WBS-0008"></a>[MAN3-WBS-0008](MAN3-PP-0001-project-plan.md#MAN3-WBS-0008) | SWE-5 통합 테스트 실행                  | [MAN3-WBS-0007](MAN3-PP-0001-project-plan.md#MAN3-WBS-0007) | ASPICE SWE-5 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |
| <a id="MAN3-WBS-0009"></a>[MAN3-WBS-0009](MAN3-PP-0001-project-plan.md#MAN3-WBS-0009) | SWE-6 적격성 테스트 케이스 작성         | —                                                           | ASPICE SWE-6 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |
| <a id="MAN3-WBS-0010"></a>[MAN3-WBS-0010](MAN3-PP-0001-project-plan.md#MAN3-WBS-0010) | SWE-6 적격성 테스트 실행 및 릴리스 판정 | [MAN3-WBS-0009](MAN3-PP-0001-project-plan.md#MAN3-WBS-0009) | ASPICE SWE-6 전문가 | 2026-04-11 | 2026-04-11 | 2026-04-11 | 100%   | Closed |

---

## 3. 마일스톤

| ID                                                                                 | 마일스톤명                             | 계획 날짜  | 실제 달성일 | 달성 기준                                                                       | 상태   | 비고                                                                                            |
| ---------------------------------------------------------------------------------- | -------------------------------------- | ---------- | ----------- | ------------------------------------------------------------------------------- | ------ | ----------------------------------------------------------------------------------------------- |
| <a id="MAN3-MS-0001"></a>[MAN3-MS-0001](MAN3-PP-0001-project-plan.md#MAN3-MS-0001) | SWE-1/2/3 산출물 완료                  | 2026-04-05 | 2026-04-05  | SWE-1 요구사항, SWE-2 아키텍처, SWE-3 상세 설계 Draft 완성 + 소스코드 구현 완료 | Closed | ✔ 달성                                                                                          |
| <a id="MAN3-MS-0002"></a>[MAN3-MS-0002](MAN3-PP-0001-project-plan.md#MAN3-MS-0002) | SWE-4 단위 검증 완료                   | 2026-04-11 | 2026-04-11  | 모든 단위 TC Pass + 문장/분기 커버리지 100%                                     | Closed | ✔ 달성 — 23/23 Pass, Calculator.cpp 구문 100%, InputParser.cpp 100%                             |
| <a id="MAN3-MS-0003"></a>[MAN3-MS-0003](MAN3-PP-0001-project-plan.md#MAN3-MS-0003) | SWE-5 통합 테스트 완료                 | 2026-04-11 | 2026-04-11  | 모든 통합 ITC Pass + 결함 0건 미해결                                            | Closed | ✔ 달성 — 13/13 Pass, 미해결 결함 0건                                                            |
| <a id="MAN3-MS-0004"></a>[MAN3-MS-0004](MAN3-PP-0001-project-plan.md#MAN3-MS-0004) | SWE-6 적격성 테스트 완료 / 릴리스 판정 | 2026-04-11 | 2026-04-11  | 모든 QTC Pass + 요구사항 추적성 100% 확보                                       | Closed | ✔ 달성 — 17/17 Pass, [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010 100% 매핑 |

---

## 4. 자원 계획

| 역할             | 담당 에이전트       | 투입 범위 |
| ---------------- | ------------------- | --------- |
| 요구사항 분석    | ASPICE SWE-1 전문가 | SWE-1     |
| 아키텍처 설계    | ASPICE SWE-2 전문가 | SWE-2     |
| 상세 설계 / 구현 | ASPICE SWE-3 전문가 | SWE-3     |
| 단위 검증        | ASPICE SWE-4 전문가 | SWE-4     |
| 통합 테스트      | ASPICE SWE-5 전문가 | SWE-5     |
| 적격성 테스트    | ASPICE SWE-6 전문가 | SWE-6     |
| 프로젝트 관리    | ASPICE MAN-3 전문가 | 전 구간   |

**빌드 도구**: g++ 13.x, CMake 3.16+, Google Test, lcov/gcovr  
**OS**: Ubuntu 22.04 LTS

---

## 5. 리스크 목록

| ID                                                                                    | 리스크 내용                                  | 발생 가능성 | 영향도 | 위험도 | 대응 계획                                                                                                                                                                           | 담당자     | 상태   | 날짜       |
| ------------------------------------------------------------------------------------- | -------------------------------------------- | ----------- | ------ | ------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ------ | ---------- |
| <a id="MAN3-RSK-0001"></a>[MAN3-RSK-0001](MAN3-PP-0001-project-plan.md#MAN3-RSK-0001) | 단위 커버리지 목표(100%) 미달성              | Medium      | High   | High   | SWE-4 단계에서 미달성 분기 식별 후 테스트 케이스 보완                                                                                                                               | SWE-4 담당 | Closed | 2026-04-11 |
| <a id="MAN3-RSK-0002"></a>[MAN3-RSK-0002](MAN3-PP-0001-project-plan.md#MAN3-RSK-0002) | calc::divide 0 나누기 예외 미검증            | Low         | High   | Medium | SWE-4 TC에 b=0 경계값 테스트 필수 포함 ([SWE-TC-0005](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md#SWE-TC-0005) 포함 완료)                                                               | SWE-4 담당 | Closed | 2026-04-11 |
| <a id="MAN3-RSK-0003"></a>[MAN3-RSK-0003](MAN3-PP-0001-project-plan.md#MAN3-RSK-0003) | SWE-5 통합 시 cli↔calc_lib 인터페이스 불일치 | Low         | Medium | Medium | [SWE-IF-0001](../SWE-2/SWE2-ARCH-0001-software-architecture.md#SWE-IF-0001)~0004 기준으로 통합 검증 완료 ([SWE5-ITC-SPEC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md) §4) | SWE-5 담당 | Closed | 2026-04-11 |
| <a id="MAN3-RSK-0004"></a>[MAN3-RSK-0004](MAN3-PP-0001-project-plan.md#MAN3-RSK-0004) | SWE-6 요구사항 추적성 누락                   | Low         | High   | Medium | [SWE-REQ-0001](../SWE-1/SWE-1-requirements.md#SWE-REQ-0001)~0010 전체 QTC 매핑 완료 ([SWE6-QTC-SPEC-0001](../SWE-6/SWE6-QTC-SPEC-0001-qualification-test.md) §6)                    | SWE-6 담당 | Closed | 2026-04-11 |

---

## 6. 이슈 목록

| ID                                                                                    | 이슈 내용                                         | 심각도 | 영향 항목                                                      | 담당자         | 발생일     | 해결 기한  | 상태   |
| ------------------------------------------------------------------------------------- | ------------------------------------------------- | ------ | -------------------------------------------------------------- | -------------- | ---------- | ---------- | ------ |
| <a id="MAN3-ISS-0001"></a>[MAN3-ISS-0001](MAN3-PP-0001-project-plan.md#MAN3-ISS-0001) | SWE-4/5/6 산출물 미작성 (담당 에이전트 배정 대기) | Medium | [MAN3-MS-0002](MAN3-PP-0001-project-plan.md#MAN3-MS-0002)~0004 | SWE-4/5/6 담당 | 2026-04-05 | 2026-04-11 | Closed |

---

## 7. 진행 현황 모니터링 (계획 대비 실적)

| 항목             | 계획 | 실적 | 편차 | 조치 사항                    |
| ---------------- | ---- | ---- | ---- | ---------------------------- |
| 완료 WBS 항목 수 | 10   | 10   | 0    | 전체 WBS 완료 ✅             |
| 마일스톤 달성 수 | 4    | 4    | 0    | MS-0001~0004 전체 Closed ✅  |
| 미해결 리스크 수 | 0    | 0    | 0    | RSK-0001~0004 전체 Closed ✅ |
| 미해결 이슈 수   | 0    | 0    | 0    | ISS-0001 Closed ✅           |

---

## 8. 다음 단계 인계 지시

아래 순서에 따라 각 전문가 에이전트가 순차적으로 수행한다.

| 순서 | 담당 에이전트           | 수행 내용                                                          | 입력 산출물                          |
| ---- | ----------------------- | ------------------------------------------------------------------ | ------------------------------------ |
| 1    | **ASPICE SWE-4 전문가** | `docs/SWE-4/` 단위 TC 작성 + `tests/` GTest 코드 + 커버리지 리포트 | SWE-3 상세 설계서 (`docs/SWE-3/`)    |
| 2    | **ASPICE SWE-5 전문가** | `docs/SWE-5/` 통합 TC 작성 + `tests/` 통합 GTest 코드 + 결과 기록  | SWE-4 TC 결과, SWE-2 인터페이스 정의 |
| 3    | **ASPICE SWE-6 전문가** | `docs/SWE-6/` 적격성 TC 작성 + 실행 결과 + 릴리스 판정             | SWE-1 요구사항, SWE-5 결과           |

---

## 9. WBS ↔ SWE/SUP 산출물 추적성 매핑표

| WBS ID                                                      | 마일스톤 ID                                               | 연계 산출물 ID / 경로                                                                               | 상태   | 비고                                                                                       |
| ----------------------------------------------------------- | --------------------------------------------------------- | --------------------------------------------------------------------------------------------------- | ------ | ------------------------------------------------------------------------------------------ |
| [MAN3-WBS-0001](MAN3-PP-0001-project-plan.md#MAN3-WBS-0001) | [MAN3-MS-0001](MAN3-PP-0001-project-plan.md#MAN3-MS-0001) | `docs/SWE-1/SWE-1-requirements.md`                                                                  | Closed |                                                                                            |
| [MAN3-WBS-0002](MAN3-PP-0001-project-plan.md#MAN3-WBS-0002) | [MAN3-MS-0001](MAN3-PP-0001-project-plan.md#MAN3-MS-0001) | `docs/SWE-2/SWE-2-architecture.md`                                                                  | Closed |                                                                                            |
| [MAN3-WBS-0003](MAN3-PP-0001-project-plan.md#MAN3-WBS-0003) | [MAN3-MS-0001](MAN3-PP-0001-project-plan.md#MAN3-MS-0001) | `docs/SWE-3/SWE-3-detailed-design.md`                                                               | Closed |                                                                                            |
| [MAN3-WBS-0004](MAN3-PP-0001-project-plan.md#MAN3-WBS-0004) | [MAN3-MS-0001](MAN3-PP-0001-project-plan.md#MAN3-MS-0001) | `src/Calculator.cpp`, `src/InputParser.cpp`, `src/AppController.cpp`, `src/types.h`, `src/main.cpp` | Closed | SUP10-CR-0001: 실제 경로로 정정                                                            |
| [MAN3-WBS-0005](MAN3-PP-0001-project-plan.md#MAN3-WBS-0005) | [MAN3-MS-0002](MAN3-PP-0001-project-plan.md#MAN3-MS-0002) | `docs/SWE-4/SWE4-TC-SPEC-0001-unit-test.md`                                                         | Closed | [SWE-TC-0001](../SWE-4/SWE4-TC-SPEC-0001-unit-test.md#SWE-TC-0001)~0023 (23건)             |
| [MAN3-WBS-0006](MAN3-PP-0001-project-plan.md#MAN3-WBS-0006) | [MAN3-MS-0002](MAN3-PP-0001-project-plan.md#MAN3-MS-0002) | `tests/unit/test_calculator.cpp`, `tests/unit/test_inputparser.cpp`                                 | Closed | 23/23 Pass, 커버리지 100%                                                                  |
| [MAN3-WBS-0007](MAN3-PP-0001-project-plan.md#MAN3-WBS-0007) | [MAN3-MS-0003](MAN3-PP-0001-project-plan.md#MAN3-MS-0003) | `docs/SWE-5/SWE5-ITC-SPEC-0001-integration-test.md`                                                 | Closed | [SWE-ITC-0001](../SWE-5/SWE5-ITC-SPEC-0001-integration-test.md#SWE-ITC-0001)~0013 (13건)   |
| [MAN3-WBS-0008](MAN3-PP-0001-project-plan.md#MAN3-WBS-0008) | [MAN3-MS-0003](MAN3-PP-0001-project-plan.md#MAN3-MS-0003) | `tests/integration/test_integration.cpp`                                                            | Closed | 13/13 Pass, 미해결 결함 0건                                                                |
| [MAN3-WBS-0009](MAN3-PP-0001-project-plan.md#MAN3-WBS-0009) | [MAN3-MS-0004](MAN3-PP-0001-project-plan.md#MAN3-MS-0004) | `docs/SWE-6/SWE6-QTC-SPEC-0001-qualification-test.md`                                               | Closed | [SWE-QTC-0001](../SWE-6/SWE6-QTC-SPEC-0001-qualification-test.md#SWE-QTC-0001)~0017 (17건) |
| [MAN3-WBS-0010](MAN3-PP-0001-project-plan.md#MAN3-WBS-0010) | [MAN3-MS-0004](MAN3-PP-0001-project-plan.md#MAN3-MS-0004) | `docs/SWE-6/SWE6-QTC-SPEC-0001-qualification-test.md` §7                                            | Closed | 17/17 Pass, 릴리스 기준 전 항목 달성                                                       |

---

## 10. 변경 이력

| 버전 | 날짜       | 변경 내용                                                                                                                               | 작성자               |
| ---- | ---------- | --------------------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| v1.0 | 2026-04-05 | 최초 작성 — SWE-1/2/3 완료 반영, SWE-4/5/6 계획 수립                                                                                    | ASPICE MAN-3 전문가  |
| v1.1 | 2026-04-12 | SWE-4/5/6 완료 반영 — WBS-0005~0010 Closed, MS-0002~0004 Closed, RSK-0001~0004 Closed, ISS-0001 Closed, 진행 현황 및 추적성 매핑표 갱신 | ASPICE MAN-3 전문가  |
| v1.2 | 2026-04-12 | SUP10-CR-0001 반영 — WBS-0004 연계 산출물 경로를 실제 구조(`src/`)로 정정                                                               | ASPICE SUP-10 전문가 |

---

## 11. 리뷰 체크리스트

- [x] 프로젝트 범위 및 완료 기준이 명확히 정의됨
- [x] 모든 WBS 항목에 고유 ID·담당자·연계 산출물 명시됨
- [x] 마일스톤 달성 기준이 정의되고 현황이 기록됨
- [x] 리스크 목록이 식별되고 대응 계획이 있음
- [x] 이슈 목록이 추적되고 담당자가 지정됨
- [x] 계획 대비 실적 편차가 분석됨
- [x] 다음 단계 인계 지시가 명확히 기술됨
- [x] 버전 및 변경 이력 기록됨
