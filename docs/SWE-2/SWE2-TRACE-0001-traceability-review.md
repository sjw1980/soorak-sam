# SWE-2 추적성 매핑표 및 리뷰 체크리스트

| 항목 | 내용 |
|------|------|
| 문서 ID | SWE2-TRACE-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-11 |
| 상태 | Draft |
| 작성자 | ASPICE SWE-2 전문가 |
| 승인자 | — |
| 참조 문서 | SWE1-REQ-SPEC-0001, SWE2-ARCH-0001 |

---

## 1. SWE-1 → SWE-2 추적성 매핑표

### 1.1 요구사항 ↔ 컴포넌트 매핑

| SW 요구사항 ID | 요구사항 제목 | 컴포넌트 ID | 컴포넌트명 | 인터페이스 ID | 상태 | 비고 |
|---------------|------------|------------|-----------|-------------|------|------|
| SWE-REQ-0001 | 덧셈 연산 | SWE-COMP-0001 | Calculator | SWE-IF-0001, SWE-IF-0002 | Covered | AppController → Calculator → 결과 반환 |
| SWE-REQ-0002 | 뺄셈 연산 | SWE-COMP-0001 | Calculator | SWE-IF-0001, SWE-IF-0002 | Covered | AppController → Calculator → 결과 반환 |
| SWE-REQ-0003 | 곱셈 연산 | SWE-COMP-0001 | Calculator | SWE-IF-0001, SWE-IF-0002 | Covered | AppController → Calculator → 결과 반환 |
| SWE-REQ-0004 | 나눗셈 연산 | SWE-COMP-0001 | Calculator | SWE-IF-0001, SWE-IF-0002 | Covered | 정상 나눗셈 (b ≠ 0) |
| SWE-REQ-0005 | 0 나누기 예외 처리 | SWE-COMP-0001 | Calculator | SWE-IF-0002 | Covered | success=false, errorMsg 반환 |
| SWE-REQ-0006 | CLI 사용자 인터페이스 | SWE-COMP-0002, SWE-COMP-0003 | InputParser, AppController | SWE-IF-0003 | Covered | 입력 파싱 후 결과 stdout 출력 |
| SWE-REQ-0007 | 반복 입력 루프 | SWE-COMP-0003 | AppController | — | Covered | AppController.run() 내 while 루프 |
| SWE-REQ-0008 | 종료 명령 처리 | SWE-COMP-0002, SWE-COMP-0003 | InputParser, AppController | SWE-IF-0003 | Covered | InputParser가 QUIT 감지 → AppController 루프 종료 |
| SWE-REQ-0009 | C++17 준수 | SWE-COMP-0001, SWE-COMP-0002, SWE-COMP-0003 | 전체 컴포넌트 | — | Covered | 전체 컴포넌트 -std=c++17 빌드 |
| SWE-REQ-0010 | 커버리지 100% | SWE-COMP-0001, SWE-COMP-0002 | Calculator, InputParser | — | Covered | 독립 클래스 분리로 단위 테스트 가능 구조 확보 |

### 1.2 미할당 요구사항 확인

| 확인 항목 | 결과 |
|---------|------|
| 미할당 요구사항 (컴포넌트 없음) | 없음 — 전체 10개 요구사항 커버됨 |
| 미연결 컴포넌트 (요구사항 없음) | 없음 — 전체 3개 컴포넌트가 요구사항에 연결됨 |
| 미연결 인터페이스 (요구사항 없음) | 없음 — 전체 3개 인터페이스가 요구사항에 연결됨 |

---

## 2. 컴포넌트 ↔ 인터페이스 매핑

| 컴포넌트 ID | 컴포넌트명 | 제공 인터페이스 | 소비 인터페이스 |
|-----------|-----------|--------------|--------------|
| SWE-COMP-0001 | Calculator | SWE-IF-0002 | SWE-IF-0001 |
| SWE-COMP-0002 | InputParser | SWE-IF-0003 | — |
| SWE-COMP-0003 | AppController | — | SWE-IF-0001, SWE-IF-0002, SWE-IF-0003 |

---

## 3. 아키텍처 리뷰 체크리스트

### 3.1 컴포넌트 완전성

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 1 | 모든 컴포넌트에 고유 ID 부여됨 (`SWE-COMP-XXXX` 형식) | ☑ Pass | SWE-COMP-0001~0003 |
| 2 | 각 컴포넌트의 책임이 명확하게 기술됨 | ☑ Pass | SWE2-ARCH-0001 §2.2 참조 |
| 3 | 컴포넌트 책임 간 중복 없음 | ☑ Pass | Calculator(연산), InputParser(파싱), AppController(제어) 명확히 분리 |
| 4 | 모든 컴포넌트의 주요 함수(인터페이스 함수)가 정의됨 | ☑ Pass | calculate(), parse(), run() |
| 5 | 비기능 요구사항(C++17, 커버리지)이 컴포넌트 명세에 반영됨 | ☑ Pass | SWE2-ARCH-0001 §6 참조 |

### 3.2 인터페이스 완전성

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 6 | 모든 인터페이스에 고유 ID 부여됨 (`SWE-IF-XXXX` 형식) | ☑ Pass | SWE-IF-0001~0003 |
| 7 | 각 인터페이스의 데이터 구조(타입, 필드)가 정의됨 | ☑ Pass | SWE2-ARCH-0001 §3.2 참조 |
| 8 | 각 인터페이스의 데이터 흐름 방향이 명확함 | ☑ Pass | 제공 컴포넌트 → 소비 컴포넌트 명시 |
| 9 | 인터페이스 프로토콜(함수 호출/반환값)이 정의됨 | ☑ Pass | C++ 메서드 호출 및 반환값 |
| 10 | 모든 컴포넌트가 최소 1개 이상의 인터페이스에 연결됨 | ☑ Pass | 상기 매핑 테이블 참조 |

### 3.3 추적성 검증

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 11 | 모든 SW 요구사항이 최소 1개 이상의 컴포넌트에 매핑됨 | ☑ Pass | 10/10 요구사항 커버 |
| 12 | SWE-REQ-0001~0004 (4칙 연산)이 Calculator에 매핑됨 | ☑ Pass | SWE-COMP-0001 |
| 13 | SWE-REQ-0005 (0 나누기 예외)가 Calculator에 매핑됨 | ☑ Pass | SWE-COMP-0001, SWE-IF-0002 |
| 14 | SWE-REQ-0006 (CLI 인터페이스)이 InputParser 및 AppController에 매핑됨 | ☑ Pass | SWE-COMP-0002, SWE-COMP-0003 |
| 15 | SWE-REQ-0007 (반복 루프)이 AppController에 매핑됨 | ☑ Pass | SWE-COMP-0003 |
| 16 | SWE-REQ-0008 (종료 명령)이 InputParser 및 AppController에 매핑됨 | ☑ Pass | SWE-COMP-0002, SWE-COMP-0003 |
| 17 | SWE-REQ-0009 (C++17)이 전체 컴포넌트에 반영됨 | ☑ Pass | SWE-COMP-0001~0003 전체 |
| 18 | SWE-REQ-0010 (커버리지)이 아키텍처 구조에 반영됨 | ☑ Pass | 독립 클래스 분리로 단위 테스트 가능 |

### 3.4 설계 품질

| # | 체크 항목 | 결과 | 비고 |
|---|---------|------|------|
| 19 | 정적 구조 다이어그램(컴포넌트 구성도)이 작성됨 | ☑ Pass | SWE2-ARCH-0001 §4.1 참조 |
| 20 | 동적 행위 다이어그램(시퀀스) — 정상 연산 흐름 기술됨 | ☑ Pass | SWE2-ARCH-0001 §5.1 참조 |
| 21 | 동적 행위 다이어그램(시퀀스) — 예외 흐름(0 나누기) 기술됨 | ☑ Pass | SWE2-ARCH-0001 §5.2 참조 |
| 22 | 동적 행위 다이어그램(시퀀스) — 종료 명령 흐름 기술됨 | ☑ Pass | SWE2-ARCH-0001 §5.3 참조 |
| 23 | 예상 소스 파일 구조가 정의됨 | ☑ Pass | SWE2-ARCH-0001 §4.2 참조 |
| 24 | 버전(v1.0) 및 날짜(2026-04-11)가 문서에 기록됨 | ☑ Pass | 문서 헤더 및 변경 이력 |

---

## 4. 리뷰 결과 요약

| 분류 | Pass | Fail | N/A |
|------|------|------|-----|
| 컴포넌트 완전성 (1~5) | 5 | 0 | 0 |
| 인터페이스 완전성 (6~10) | 5 | 0 | 0 |
| 추적성 검증 (11~18) | 8 | 0 | 0 |
| 설계 품질 (19~24) | 6 | 0 | 0 |
| **합계** | **24** | **0** | **0** |

> **리뷰 결론**: 전체 24개 체크 항목 Pass. SWE2-ARCH-0001 문서는 Approved 조건을 충족함.

---

## 5. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-11 | 최초 작성 — SWE-1 10개 요구사항 추적성 매핑, 24개 리뷰 항목 검토 완료 | ASPICE SWE-2 전문가 |
