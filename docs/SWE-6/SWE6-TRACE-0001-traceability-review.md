# SWE-6 적격성 테스트 추적성 검토 보고서

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE6-TRACE-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-6 전문가 |
| 승인자 | — |
| 참조 문서 | SWE6-QTC-SPEC-0001, SWE5-ITC-SPEC-0001, SWE4-TC-SPEC-0001, SWE1-REQ-SPEC-0001 |

---

## 1. 목적

본 문서는 SWE-6 소프트웨어 적격성 테스트 활동의 추적성을 검토하고 기록한다.  
SW 요구사항(SWE-REQ) ↔ 단위 TC(SWE-TC) ↔ 통합 ITC(SWE-ITC) ↔ 적격성 QTC(SWE-QTC) 간의  
전방향/역방향 추적성을 매핑하여 SWE-1~SWE-6 전 단계 추적성 완결성을 확인한다.

---

## 2. 전방향 추적성 (SW 요구사항 → 적격성 QTC)

| SWE-REQ ID | 요구사항 요약 | 단위 TC ID | 통합 ITC ID | 적격성 QTC ID | 적격성 검증 상태 |
|-----------|-----------|----------|-----------|-------------|--------------|
| SWE-REQ-0001 | 덧셈 연산 | SWE-TC-0001, SWE-TC-0006 | SWE-ITC-0001, SWE-ITC-0007 | SWE-QTC-0001, SWE-QTC-0006 | ✅ |
| SWE-REQ-0002 | 뺄셈 연산 | SWE-TC-0002 | SWE-ITC-0002 | SWE-QTC-0002 | ✅ |
| SWE-REQ-0003 | 곱셈 연산 | SWE-TC-0003 | SWE-ITC-0003 | SWE-QTC-0003 | ✅ |
| SWE-REQ-0004 | 나눗셈 연산 | SWE-TC-0004, SWE-TC-0007 | SWE-ITC-0004, SWE-ITC-0006 | SWE-QTC-0004, SWE-QTC-0005 | ✅ |
| SWE-REQ-0005 | 0 나누기 예외 처리 | SWE-TC-0005, SWE-TC-0014 | SWE-ITC-0005 | SWE-QTC-0007, SWE-QTC-0008 | ✅ |
| SWE-REQ-0006 | CLI 유효 입력 파싱 | SWE-TC-0013, SWE-TC-0019~0021 | SWE-ITC-0001~0007, SWE-ITC-0013 | SWE-QTC-0012, SWE-QTC-0013 | ✅ |
| SWE-REQ-0007 | 반복 루프 및 잘못된 입력 처리 | SWE-TC-0015~0016, SWE-TC-0018, SWE-TC-0022~0023 | SWE-ITC-0010~0013 | SWE-QTC-0009, SWE-QTC-0010, SWE-QTC-0011, SWE-QTC-0013 | ✅ |
| SWE-REQ-0008 | 종료 명령 처리 | SWE-TC-0009~0012 | SWE-ITC-0008, SWE-ITC-0009 | SWE-QTC-0014, SWE-QTC-0015 | ✅ |
| SWE-REQ-0009 | C++17 표준 준수 | SWE-TC-0008, SWE-TC-0017 | SWE-ITC-0012 | SWE-QTC-0016 | ✅ |
| SWE-REQ-0010 | 단위 커버리지 100% | — (커버리지 분석) | — | SWE-QTC-0017 | ✅ |

---

## 3. 역방향 추적성 (적격성 QTC → SW 요구사항)

| SWE-QTC ID | 테스트명 | 매핑 SWE-REQ ID | 대응 SWE-ITC ID | QTC 결과 |
|-----------|---------|----------------|----------------|---------|
| SWE-QTC-0001 | 덧셈 연산 적격성 검증 | SWE-REQ-0001 | SWE-ITC-0001 | Pass |
| SWE-QTC-0002 | 뺄셈 연산 적격성 검증 | SWE-REQ-0002 | SWE-ITC-0002 | Pass |
| SWE-QTC-0003 | 곱셈 연산 적격성 검증 | SWE-REQ-0003 | SWE-ITC-0003 | Pass |
| SWE-QTC-0004 | 나눗셈 연산 적격성 검증 | SWE-REQ-0004 | SWE-ITC-0004 | Pass |
| SWE-QTC-0005 | 소수 나눗셈 결과 적격성 검증 | SWE-REQ-0004 | SWE-ITC-0006 | Pass |
| SWE-QTC-0006 | 음수 피연산자 연산 적격성 검증 | SWE-REQ-0001 | SWE-ITC-0007 | Pass |
| SWE-QTC-0007 | 0 나누기 오류 메시지 적격성 검증 | SWE-REQ-0005 | SWE-ITC-0005 | Pass |
| SWE-QTC-0008 | 0 나누기 후 프로그램 정상 유지 | SWE-REQ-0005 | SWE-ITC-0005 (확장) | Pass |
| SWE-QTC-0009 | 잘못된 입력 후 루프 유지 | SWE-REQ-0007 | SWE-ITC-0010 | Pass |
| SWE-QTC-0010 | 빈 입력 처리 후 루프 유지 | SWE-REQ-0007 | SWE-ITC-0011 | Pass |
| SWE-QTC-0011 | 알 수 없는 연산자 처리 | SWE-REQ-0007 | SWE-ITC-0012 | Pass |
| SWE-QTC-0012 | CLI 소수 입력 파싱 적격성 검증 | SWE-REQ-0006 | SWE-ITC-0006 | Pass |
| SWE-QTC-0013 | 다중 연산 반복 루프 적격성 검증 | SWE-REQ-0006, SWE-REQ-0007 | SWE-ITC-0013 (확장) | Pass |
| SWE-QTC-0014 | q 명령 정상 종료 | SWE-REQ-0008 | SWE-ITC-0008 | Pass |
| SWE-QTC-0015 | quit 명령 정상 종료 | SWE-REQ-0008 | SWE-ITC-0009 | Pass |
| SWE-QTC-0016 | C++17 빌드 플래그 적격성 검증 | SWE-REQ-0009 | — (정적 확인) | Pass |
| SWE-QTC-0017 | 단위 테스트 커버리지 100% 적격성 검증 | SWE-REQ-0010 | — (gcov 참조) | Pass |

---

## 4. SWE-1~SWE-6 전 단계 추적성 완결성 요약

| SWE-REQ ID | SWE-3 단위 | SWE-4 단위 TC | SWE-5 통합 ITC | SWE-6 적격성 QTC | 완결 여부 |
|-----------|-----------|-------------|--------------|----------------|---------|
| SWE-REQ-0001 | SWE-UNIT-0001 | SWE-TC-0001, 0006 | SWE-ITC-0001, 0007 | SWE-QTC-0001, 0006 | ✅ 완결 |
| SWE-REQ-0002 | SWE-UNIT-0001 | SWE-TC-0002 | SWE-ITC-0002 | SWE-QTC-0002 | ✅ 완결 |
| SWE-REQ-0003 | SWE-UNIT-0001 | SWE-TC-0003 | SWE-ITC-0003 | SWE-QTC-0003 | ✅ 완결 |
| SWE-REQ-0004 | SWE-UNIT-0001 | SWE-TC-0004, 0007 | SWE-ITC-0004, 0006 | SWE-QTC-0004, 0005 | ✅ 완결 |
| SWE-REQ-0005 | SWE-UNIT-0001 | SWE-TC-0005, 0014 | SWE-ITC-0005 | SWE-QTC-0007, 0008 | ✅ 완결 |
| SWE-REQ-0006 | SWE-UNIT-0002 | SWE-TC-0013, 0019~0021 | SWE-ITC-0001~0007, 0013 | SWE-QTC-0012, 0013 | ✅ 완결 |
| SWE-REQ-0007 | SWE-UNIT-0002 | SWE-TC-0015~0016, 0018, 0022~0023 | SWE-ITC-0010~0013 | SWE-QTC-0009~0011, 0013 | ✅ 완결 |
| SWE-REQ-0008 | SWE-UNIT-0002 | SWE-TC-0009~0012 | SWE-ITC-0008, 0009 | SWE-QTC-0014, 0015 | ✅ 완결 |
| SWE-REQ-0009 | SWE-UNIT-0001 | SWE-TC-0008, 0017 | SWE-ITC-0012 | SWE-QTC-0016 | ✅ 완결 |
| SWE-REQ-0010 | — (커버리지) | — (gcov 분석) | — | SWE-QTC-0017 | ✅ 완결 |

---

## 5. 미검증 항목 현황

| 구분 | 항목 | 사유 | 조치 |
|------|------|------|------|
| 미검증 요구사항 | 없음 | — | — |
| 미매핑 QTC | 없음 | — | — |
| 미실행 QTC | 없음 | — | — |
| 미해결 결함 | 없음 | — | — |

> **결론**: SWE-6 적격성 테스트 추적성 검토 결과 모든 SW 요구사항(SWE-REQ-0001~0010)이  
> SWE-3 단위 설계 → SWE-4 단위 TC → SWE-5 통합 ITC → SWE-6 적격성 QTC까지  
> 전 단계 추적성이 완결되었으며, 미검증 항목 없음.  
> **릴리스 기준 전 항목 달성 — 소프트웨어 릴리스 적격 판정.**

---

## 6. 변경 이력

| 버전 | 날짜 | 변경 내용 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — SWE-1~SWE-6 전 단계 추적성 매핑 완료, 미검증 항목 없음 확인 | ASPICE SWE-6 전문가 |
