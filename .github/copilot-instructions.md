# ASPICE 프로젝트 공통 지침

이 워크스페이스는 ASPICE(Automotive SPICE) 기반 소프트웨어 개발 프로젝트입니다.
모든 에이전트는 아래의 공통 약어, ID 체계, 규칙을 준수해야 합니다.

---

## 공통 약어 (Abbreviations)

### 프로세스 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| ASPICE | Automotive Software Process Improvement and Capability dEtermination | 자동차 SW 프로세스 개선 및 역량 평가 표준 |
| SWE | Software Engineering | 소프트웨어 엔지니어링 프로세스 그룹 (SWE-1~SWE-6) |
| SPL | Software Product Line | 소프트웨어 제품 라인 프로세스 그룹 (SPL-2) |
| SUP | Supporting | 지원 프로세스 그룹 (SUP-1, SUP-8, SUP-9, SUP-10) |
| MAN | Management | 관리 프로세스 그룹 (MAN-3) |
| QA | Quality Assurance | 품질 보증 (SUP-1) |
| CM | Configuration Management | 형상 관리 (SUP-8) |
| PRM | Problem Resolution Management | 문제 해결 관리 (SUP-9) |
| CRM | Change Request Management | 변경 요청 관리 (SUP-10) |
| PM | Project Management | 프로젝트 관리 (MAN-3) |

### 산출물 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| REQ | Requirement | 소프트웨어 요구사항 |
| COMP | Component | 소프트웨어 컴포넌트 |
| IF | Interface | 인터페이스 |
| UNIT | Unit | 소프트웨어 단위 |
| TC | Test Case | 단위 테스트 케이스 |
| ITC | Integration Test Case | 통합 테스트 케이스 |
| QTC | Qualification Test Case | 적격성 테스트 케이스 |
| DEF | Defect | 결함 |
| NC | Non-Conformance | 부적합 사항 (SUP-1) |
| CA | Corrective Action | 시정 조치 (SUP-1) |
| CI | Configuration Item | 형상 항목 (SUP-8) |
| BL | Baseline | 베이스라인 (SUP-8) |
| CR | Change Request | 변경 요청 (SUP-8/SUP-10) |
| PR | Problem Report | 문제 보고서 (SUP-9) |
| AP | Action Plan | 해결 계획 (SUP-9) |
| CAP | Corrective Action Plan | 재발 방지 조치 계획 |
| IA | Impact Analysis | 영향 분석 (SUP-10) |
| CCB | Change Control Board | 변경 제어 위원회 |
| WBS | Work Breakdown Structure | 작업 분류 체계 (MAN-3) |
| MS | Milestone | 마일스톤 (MAN-3) |
| RSK | Risk | 리스크 (MAN-3) |
| ISS | Issue | 이슈 (MAN-3) |
| PP | Project Plan | 프로젝트 계획서 (MAN-3) |
| QAP | Quality Assurance Plan | 품질 보증 계획 (SUP-1) |
| CMP | Configuration Management Plan | 형상 관리 계획 (SUP-8) |
| RCA | Root Cause Analysis | 근본 원인 분석 |
| FEAT | Feature | 피처 모델 항목 (SPL-2) |
| BUILD | Build Activity | 빌드 활동 정의 (SPL-2) |
| REL | Release | 출시 노트 (SPL-2) |

### 기술 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| SW | Software | 소프트웨어 |
| HW | Hardware | 하드웨어 |
| SYS | System | 시스템 |
| MC/DC | Modified Condition/Decision Coverage | 수정된 조건/판定 커버리지 |
| API | Application Programming Interface | 응용 프로그램 인터페이스 |
| FMEA | Failure Mode and Effects Analysis | 고장 모드 및 영향 분석 |
| AUTOSAR | AUTomotive Open System ARchitecture | 자동차 개방형 시스템 아키텍처 |
| CAN | Controller Area Network | 계측 제어기 통신망 |
| CASE | Computer-Aided Software Engineering | 컴퓨터 지원 소프트웨어 공학 |
| CPU | Central Processing Unit | 중앙 처리 장치 |
| ECU | Electronic Control Unit | 전자 제어 장치 |
| EEPROM | Electrically Erasable Programmable Read-Only Memory | 전기적으로 소거 및 프로그램 가능 읽기 전용 메모리 |
| I/O | Input / Output | 입력/출력 |
| LIN | Local Interconnect Network | 로컬 상호 연결 네트워크 |
| MISRA | Motor Industry Software Reliability Association | 자동차 산업 소프트웨어 신뢰성 협회 |
| MOST | Media Oriented Systems Transport | 미디어 지향 시스템 전송 |
| PWM | Pulse Width Modulation | 펄스 폭 변조 |
| RAM | Random Access Memory | 임의 접근 메모리 |
| ROM | Read Only Memory | 읽기 전용 메모리 |
| USB | Universal Serial Bus | 범용 직렬 버스 |

### 표준·기관 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| AS | Automotive SPICE | 자동차 SPICE (ASPICE의 약칭) |
| IEC | International Electrotechnical Commission | 국제 전기 기술 위원회 |
| IEEE | Institute of Electrical and Electronics Engineers | 전기 전자 기술자 협회 |
| ISO | International Organization for Standardization | 국제 표준화 기구 |
| MISRA | Motor Industry Software Reliability Association | 자동차 산업 소프트웨어 신뢰성 협회 |
| SPICE | Software Process Improvement and Capability dEtermination | 소프트웨어 프로세스 개선 및 능력 평가 |
| SUG | SPICE User Group | SPICE 사용자 그룹 |

### 프로세스 모델 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| BP | Base Practice | 기본 사례 — 프로세스 수행의 필수 활동 |
| GP | Generic Practice | 일반 사례 — 프로세스 능력 수준 달성을 위한 활동 |
| GR | Generic Resource | 일반 자원 — 프로세스 수행에 필요한 자원 |
| PA | Process Attribute | 프로세스 속성 — 능력 수준 측정 기준 |
| PAM | Process Assessment Model | 프로세스 평가 모델 |
| PRM | Process Reference Model | 프로세스 참조 모델 |
| WP | Work Product | 작업 산출물 |
| WPC | Work Product Characteristic | 작업 산출물 특징 |

### 계약·조달 약어

| 약어 | 전체 명칭 | 설명 |
|------|---------|------|
| CFP | Call For Proposals | 제안 요청서 |
| ITT | Invitation To Tender | 입찰 초청서 |

---

## 공통 ID 체계

모든 산출물 ID는 아래 형식을 따릅니다:

```
<프로세스>-<유형>-<4자리 일련번호>
예: SWE-REQ-0001, SUP9-PR-0003, MAN3-RSK-0002
```

| 프로세스 | 접두사 | 예시 |
|---------|--------|------|
| SWE-1 요구사항 | `SWE-REQ-` | `SWE-REQ-0001` |
| SWE-2 컴포넌트 | `SWE-COMP-` | `SWE-COMP-0001` |
| SWE-2 인터페이스 | `SWE-IF-` | `SWE-IF-0001` |
| SWE-3 단위 | `SWE-UNIT-` | `SWE-UNIT-0001` |
| SWE-4 단위 TC | `SWE-TC-` | `SWE-TC-0001` |
| SWE-5 통합 ITC | `SWE-ITC-` | `SWE-ITC-0001` |
| SWE-5 결함 | `SWE-DEF-` | `SWE-DEF-0001` |
| SWE-6 적격성 QTC | `SWE-QTC-` | `SWE-QTC-0001` |
| SUP-1 부적합 | `SUP1-NC-` | `SUP1-NC-0001` |
| SUP-1 시정 조치 | `SUP1-CA-` | `SUP1-CA-0001` |
| SUP-8 형상 항목 | `SUP8-CI-` | `SUP8-CI-0001` |
| SUP-8 베이스라인 | `SUP8-BL-` | `SUP8-BL-0001` |
| SUP-9 문제 보고서 | `SUP9-PR-` | `SUP9-PR-0001` |
| SUP-9 해결 계획 | `SUP9-AP-` | `SUP9-AP-0001` |
| SUP-10 변경 요청 | `SUP10-CR-` | `SUP10-CR-0001` |
| SUP-10 영향 분석 | `SUP10-IA-` | `SUP10-IA-0001` |
| MAN-3 WBS | `MAN3-WBS-` | `MAN3-WBS-0001` |
| MAN-3 마일스톤 | `MAN3-MS-` | `MAN3-MS-0001` |
| MAN-3 리스크 | `MAN3-RSK-` | `MAN3-RSK-0001` |
| MAN-3 이슈 | `MAN3-ISS-` | `MAN3-ISS-0001` |
| SPL-2 피처 | `SPL2-FEAT-` | `SPL2-FEAT-0001` |
| SPL-2 빌드 활동 | `SPL2-BUILD-` | `SPL2-BUILD-0001` |
| SPL-2 출시 노트 | `SPL2-REL-` | `SPL2-REL-0001` |

---

## 공통 버전 형식

모든 산출물의 버전은 아래 두 형식을 함께 사용합니다:

```
버전: v1.0 / 2026-04-05
```

- 주버전(Major): 승인된 기준선 변경 시 증가 (v1.0 → v2.0)
- 부버전(Minor): 미승인 초안 수정 시 증가 (v1.0 → v1.1)

---

## 공통 상태값

| 상태 | 설명 |
|------|------|
| Draft | 초안 — 검토 전 |
| In Review | 검토 중 |
| Approved | 승인됨 |
| Rejected | 반려됨 |
| Open | 미해결 |
| In Progress | 진행 중 |
| Resolved | 해결됨 (검증 대기) |
| Closed | 종료됨 (검증 완료) |
| Blocked | 차단됨 |
