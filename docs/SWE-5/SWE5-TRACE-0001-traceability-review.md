# SWE-5 통합 테스트 추적성 검토 보고서

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE5-TRACE-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-5 전문가 |
| 승인자 | — |
| 참조 문서 | SWE5-ITC-SPEC-0001, SWE4-TC-SPEC-0001, SWE2-ARCH-0001, SWE1-REQ-SPEC-0001 |

---

## 1. 목적

본 문서는 SWE-5 소프트웨어 통합 테스트 활동의 추적성을 검토하고 기록한다.  
SW 요구사항(SWE-REQ) ↔ 아키텍처 인터페이스(SWE-IF) ↔ 단위 TC(SWE-TC) ↔ 통합 ITC(SWE-ITC) 간의  
전방향/역방향 추적성을 매핑하여 누락된 검증 항목을 식별한다.

---

## 2. 전방향 추적성 (SW 요구사항 → 통합 ITC)

| SWE-REQ ID | 요구사항 요약 | 연관 SWE-IF ID | 연관 SWE-TC ID | 매핑 SWE-ITC ID | 통합 검증 상태 |
|-----------|-----------|--------------|--------------|----------------|--------------|
| SWE-REQ-0001 | 덧셈 연산 | SWE-IF-0001, SWE-IF-0002 | SWE-TC-0001, SWE-TC-0006 | SWE-ITC-0001, SWE-ITC-0007 | ✅ |
| SWE-REQ-0002 | 뺄셈 연산 | SWE-IF-0001, SWE-IF-0002 | SWE-TC-0002 | SWE-ITC-0002 | ✅ |
| SWE-REQ-0003 | 곱셈 연산 | SWE-IF-0001, SWE-IF-0002 | SWE-TC-0003 | SWE-ITC-0003 | ✅ |
| SWE-REQ-0004 | 나눗셈 연산 | SWE-IF-0001, SWE-IF-0002 | SWE-TC-0004, SWE-TC-0007 | SWE-ITC-0004, SWE-ITC-0006 | ✅ |
| SWE-REQ-0005 | 0 나누기 처리 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | SWE-TC-0005, SWE-TC-0014 | SWE-ITC-0005 | ✅ |
| SWE-REQ-0006 | 유효 입력 파싱 | SWE-IF-0003 | SWE-TC-0013, SWE-TC-0019~0021 | SWE-ITC-0001~0007, SWE-ITC-0013 | ✅ |
| SWE-REQ-0007 | 잘못된 입력 처리 | SWE-IF-0003 | SWE-TC-0015, SWE-TC-0016, SWE-TC-0018, SWE-TC-0022~0023 | SWE-ITC-0010, SWE-ITC-0011 | ✅ |
| SWE-REQ-0008 | 종료 명령 처리 | SWE-IF-0003 | SWE-TC-0009~0012 | SWE-ITC-0008, SWE-ITC-0009 | ✅ |
| SWE-REQ-0009 | 알 수 없는 연산자 | SWE-IF-0001, SWE-IF-0003 | SWE-TC-0008, SWE-TC-0017 | SWE-ITC-0012 | ✅ |
| SWE-REQ-0010 | 결과 출력 형식 | SWE-IF-0002 | — (SWE-4 미포함) | SWE-ITC-0001~0007, SWE-ITC-0013 | ✅ E2E 출력 형식 검증 |

---

## 3. 역방향 추적성 (통합 ITC → SW 요구사항)

| SWE-ITC ID | 테스트명 | 매핑 SWE-REQ ID | 인터페이스 ID | ITC 결과 |
|-----------|---------|----------------|------------|---------|
| SWE-ITC-0001 | 덧셈 연산 E2E | SWE-REQ-0001, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0002 | 뺄셈 연산 E2E | SWE-REQ-0002, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0003 | 곱셈 연산 E2E | SWE-REQ-0003, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0004 | 나눗셈 연산 E2E | SWE-REQ-0004, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0005 | 0 나누기 오류 E2E | SWE-REQ-0005 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0006 | 소수 연산 E2E | SWE-REQ-0004, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0007 | 음수 피연산자 E2E | SWE-REQ-0001, SWE-REQ-0006 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |
| SWE-ITC-0008 | q 입력 → 정상 종료 | SWE-REQ-0008 | SWE-IF-0003 | Pass |
| SWE-ITC-0009 | quit 입력 → 정상 종료 | SWE-REQ-0008 | SWE-IF-0003 | Pass |
| SWE-ITC-0010 | 잘못된 입력 오류 처리 | SWE-REQ-0007 | SWE-IF-0003 | Pass |
| SWE-ITC-0011 | 빈 입력 오류 처리 | SWE-REQ-0007 | SWE-IF-0003 | Pass |
| SWE-ITC-0012 | 알 수 없는 연산자 처리 | SWE-REQ-0007, SWE-REQ-0009 | SWE-IF-0001, SWE-IF-0003 | Pass |
| SWE-ITC-0013 | 다중 연산 후 종료 | SWE-REQ-0001, SWE-REQ-0004, SWE-REQ-0007, SWE-REQ-0010 | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 | Pass |

---

## 4. 인터페이스 커버리지

| SWE-IF ID | 인터페이스 설명 | 매핑 ITC 수 | 커버리지 상태 |
|----------|--------------|-----------|------------|
| SWE-IF-0001 | AppController → Calculator (OperationRequest) | 9건 (ITC-0001~0007, ITC-0012, ITC-0013) | ✅ 완전 커버 |
| SWE-IF-0002 | Calculator → AppController (OperationResult) | 8건 (ITC-0001~0007, ITC-0013) | ✅ 완전 커버 |
| SWE-IF-0003 | InputParser → AppController (ParsedInput) | 13건 (ITC-0001~0013 전체) | ✅ 완전 커버 |

---

## 5. 미검증 항목 현황

| 구분 | 항목 | 사유 | 조치 |
|------|------|------|------|
| 미검증 요구사항 | 없음 | — | — |
| 미매핑 인터페이스 | 없음 | — | — |
| 미실행 ITC | 없음 | — | — |

> **결론**: SWE-5 통합 테스트 추적성 검토 결과 모든 SW 요구사항(SWE-REQ-0001~0010) 및  
> 모든 SWE-2 인터페이스(SWE-IF-0001~0003)가 통합 ITC에 완전히 매핑되어 있으며, 미검증 항목 없음.

---

## 6. 변경 이력

| 버전 | 날짜 | 변경 내용 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — 전방향/역방향 추적성 매핑 및 인터페이스 커버리지 검토 완료 | ASPICE SWE-5 전문가 |
