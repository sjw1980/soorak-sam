# SPL-2 피처 모델 (Feature Model)

| 항목 | 내용 |
|------|------|
| 문서 ID | SPL2-FEAT-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-05 |
| 상태 | Draft |
| 작성자 | ASPICE SPL-2 전문가 |
| 승인자 | — |

---

## 1. 개요

CLI 계산기 소프트웨어의 소프트웨어 제품 피처(Feature)를 공통(Common) / 가변(Variable) 분류에 따라 정의한다.  
공통 피처는 모든 빌드 변형(variant)에 포함되며, 가변 피처는 빌드 설정에 따라 선택적으로 활성화된다.

---

## 2. 피처 목록

| ID | 피처명 | 공통/가변 | 관련 빌드 플래그 / 설정 | 연관 요구사항 | 버전 | 날짜 | 상태 |
|----|--------|---------|----------------------|------------|------|------|------|
| SPL2-FEAT-0001 | 덧셈 연산 (Addition) | 공통 | — | SWE-REQ-0001 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0002 | 뺄셈 연산 (Subtraction) | 공통 | — | SWE-REQ-0002 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0003 | 곱셈 연산 (Multiplication) | 공통 | — | SWE-REQ-0003 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0004 | 나눗셈 연산 (Division) | 공통 | — | SWE-REQ-0004 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0005 | 0 나누기 예외 처리 | 공통 | — | SWE-REQ-0005 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0006 | CLI 사용자 인터페이스 | 공통 | — | SWE-REQ-0006 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0007 | 반복 입력 루프 | 공통 | — | SWE-REQ-0007 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0008 | 종료 명령 처리 | 공통 | — | SWE-REQ-0008 | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0009 | Debug 빌드 변형 | 가변 | `CMAKE_BUILD_TYPE=Debug` | — | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0010 | Release 빌드 변형 | 가변 | `CMAKE_BUILD_TYPE=Release` | — | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0011 | 단위 테스트 빌드 (Google Test) | 가변 | `BUILD_TESTING=ON` | — | v1.0 | 2026-04-05 | Approved |
| SPL2-FEAT-0012 | 코드 커버리지 측정 | 가변 | `--coverage -fprofile-arcs -ftest-coverage` | — | v1.0 | 2026-04-05 | Approved |

---

## 3. 피처 분류 요약

| 분류 | 피처 수 | 피처 ID 범위 |
|------|--------|------------|
| 공통 (Common) | 8 | SPL2-FEAT-0001 ~ SPL2-FEAT-0008 |
| 가변 (Variable) | 4 | SPL2-FEAT-0009 ~ SPL2-FEAT-0012 |
| **합계** | **12** | — |

---

## 4. 피처 의존성

```
SPL2-FEAT-0009 (Debug)
  └─ 활성화 시 → SPL2-FEAT-0011 (단위 테스트) 가능
                → SPL2-FEAT-0012 (커버리지 측정) 가능

SPL2-FEAT-0010 (Release)
  └─ 활성화 시 → SPL2-FEAT-0011, SPL2-FEAT-0012 비활성화 권장

SPL2-FEAT-0004 (나눗셈)
  └─ 필수 연계 → SPL2-FEAT-0005 (0 나누기 예외 처리)
```

---

## 5. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-05 | 최초 작성 — 피처 목록 12개 정의 | ASPICE SPL-2 전문가 |
