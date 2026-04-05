# SPL-2 빌드 환경 및 빌드 활동 정의

| 항목 | 내용 |
|------|------|
| 문서 ID | SPL2-BUILD-0001 |
| 프로젝트명 | CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6 |
| 버전 | v1.0 / 2026-04-05 |
| 상태 | Draft |
| 작성자 | ASPICE SPL-2 전문가 |
| 승인자 | — |

---

## 1. 빌드 환경 정의 (Build Environment)

### 1.1 툴체인 및 플랫폼

| 항목 | 값 | 비고 |
|------|---|------|
| 운영체제 | Ubuntu 22.04 LTS (x86_64) | 재현 가능 빌드 기반 OS |
| 컴파일러 | g++ 13.x (GNU C++ Compiler) | C++17 이상 지원 |
| C 컴파일러 | gcc 13.x | 링킹 및 커버리지 도구 |
| 빌드 시스템 | CMake 3.16 이상 | `cmake_minimum_required(VERSION 3.16)` |
| 빌드 생성기 | Unix Makefiles (기본) | `cmake -G "Unix Makefiles"` |
| 테스트 프레임워크 | Google Test (GTest) 1.14.x | `FetchContent` 또는 시스템 패키지 |
| 커버리지 도구 | lcov 1.14 이상 / gcovr 5.x | Debug 빌드 전용 |
| 아카이브/링커 | ar, ld (GNU Binutils) | g++에 포함 |

### 1.2 빌드 디렉터리 구조

```
프로젝트 루트/
├── CMakeLists.txt          # 루트 빌드 설정
├── include/                # 퍼블릭 헤더 (calc.h 등)
├── src/
│   ├── calc_lib/           # 연산 라이브러리 소스
│   └── cli/                # CLI 메인 소스
├── tests/                  # 단위 테스트 소스 (Google Test)
└── build/                  # CMake 빌드 출력 (버전 관리 제외)
    ├── Debug/
    └── Release/
```

### 1.3 필수 환경 변수

| 환경 변수 | 값 (예시) | 비고 |
|----------|---------|------|
| `CC` | `gcc-13` | C 컴파일러 명시 |
| `CXX` | `g++-13` | C++ 컴파일러 명시 |
| `CMAKE_BUILD_TYPE` | `Debug` / `Release` | 빌드 변형 선택 |

### 1.4 컴파일 플래그

| 빌드 타입 | 컴파일 플래그 | 설명 |
|----------|------------|------|
| 공통 | `-Wall -Wextra -std=c++17` | 경고 활성화, C++17 표준 |
| Debug | `-g -O0 --coverage -fprofile-arcs -ftest-coverage` | 디버그 정보 + 커버리지 |
| Release | `-O2 -DNDEBUG` | 최적화, assert 비활성화 |

---

## 2. 빌드 활동 정의 (Build Activity)

### 2.1 공통 빌드 단계

| 순서 | ID | 빌드 단계명 | 도구 / 명령 | 입력 | 산출물 | 공통 여부 | 비고 |
|------|-----|-----------|-----------|------|--------|---------|------|
| 1 | SPL2-BUILD-0001 | CMake 구성 (Configure) | `cmake -S . -B build -DCMAKE_BUILD_TYPE=<타입>` | `CMakeLists.txt`, 소스 | `build/Makefile`, `build/CMakeCache.txt` | 공통 | 최초 1회 또는 CMakeLists 변경 시 |
| 2 | SPL2-BUILD-0002 | calc_lib 정적 라이브러리 빌드 | `cmake --build build --target calc_lib` | `src/calc_lib/*.cpp`, `include/*.h` | `build/libcalc_lib.a` | 공통 | CLI 빌드의 선행 조건 |
| 3 | SPL2-BUILD-0003 | CLI 실행 파일 빌드 | `cmake --build build --target calculator` | `src/cli/main.cpp`, `libcalc_lib.a` | `build/calculator` | 공통 | 릴리스 배포 대상 |
| 4 | SPL2-BUILD-0004 | 전체 빌드 (All Targets) | `cmake --build build` | 전체 소스 | `libcalc_lib.a`, `calculator`, `calculator_test` | 공통 | 개발 /CI 환경 표준 명령 |

### 2.2 Debug 전용 빌드 단계 (가변)

| 순서 | ID | 빌드 단계명 | 도구 / 명령 | 입력 | 산출물 | 공통 여부 | 비고 |
|------|-----|-----------|-----------|------|--------|---------|------|
| 5 | SPL2-BUILD-0005 | 단위 테스트 바이너리 빌드 | `cmake --build build --target calculator_test` | `tests/*.cpp`, `libcalc_lib.a` | `build/calculator_test` | 가변 (Debug) | `BUILD_TESTING=ON` 필요 |
| 6 | SPL2-BUILD-0006 | 단위 테스트 실행 | `ctest --test-dir build -V` 또는 `./build/calculator_test` | `calculator_test` | 테스트 결과 (stdout / JUnit XML) | 가변 (Debug) | SWE-4 검증 활동과 연계 |
| 7 | SPL2-BUILD-0007 | 커버리지 데이터 초기화 | `lcov --zerocounters --directory build` | `build/*.gcda` 파일 | 초기화된 카운터 | 가변 (Debug) | 테스트 실행 전 수행 |
| 8 | SPL2-BUILD-0008 | 커버리지 데이터 수집 | `lcov --capture --directory build --output-file build/coverage.info` | `build/*.gcda`, `*.gcno` | `build/coverage.info` | 가변 (Debug) | 테스트 실행 후 수행 |
| 9 | SPL2-BUILD-0009 | 커버리지 HTML 보고서 생성 | `genhtml build/coverage.info --output-directory build/coverage_html` | `build/coverage.info` | `build/coverage_html/index.html` | 가변 (Debug) | SWE-4 커버리지 증거 산출물 |

### 2.3 Release 전용 빌드 단계 (가변)

| 순서 | ID | 빌드 단계명 | 도구 / 명령 | 입력 | 산출물 | 공통 여부 | 비고 |
|------|-----|-----------|-----------|------|--------|---------|------|
| 10 | SPL2-BUILD-0010 | Release 패키징 | `cmake --build build --config Release` | `calculator` (Release 바이너리) | `build/Release/calculator` | 가변 (Release) | 릴리스 배포용 최적화 바이너리 |

---

## 3. 빌드 재현성 기준

| 항목 | 요건 |
|------|------|
| 컴파일러 버전 고정 | `g++-13` 명시 (`CC`, `CXX` 환경 변수 또는 `cmake -DCMAKE_CXX_COMPILER=g++-13`) |
| 빌드 타입 명시 | `-DCMAKE_BUILD_TYPE=Debug` 또는 `Release` 항상 명시 |
| 외부 의존성 버전 고정 | Google Test 버전을 `FetchContent` 태그로 고정 (`v1.14.0`) |
| 빌드 디렉터리 격리 | `build/` 디렉터리를 버전 관리(git)에서 제외 (`.gitignore`) |
| 클린 빌드 절차 | `cmake --build build --clean-first` 또는 `build/` 삭제 후 재구성 |

---

## 4. 빌드 활동 연계 (SPL-2 ↔ SWE 프로세스)

| 빌드 활동 ID | 연관 SWE 단계 | 연계 내용 |
|------------|------------|---------|
| SPL2-BUILD-0002 | SWE-3 (소스코드 구현) | calc_lib 소스 변경 시 재빌드 트리거 |
| SPL2-BUILD-0005 | SWE-4 (단위 테스트) | 단위 테스트 바이너리 빌드 — SWE-4 검증의 선행 조건 |
| SPL2-BUILD-0006 | SWE-4 (단위 테스트) | 테스트 실행 결과 — SWE-TC 결과 기록에 사용 |
| SPL2-BUILD-0008, 0009 | SWE-4 (단위 테스트) | 커버리지 데이터 — 문장/분기 커버리지 100% 달성 증거 |
| SPL2-BUILD-0003 | SWE-5 (통합 테스트) | CLI 실행 파일 — SWE-5 통합 테스트 대상 |
| SPL2-BUILD-0004 | SWE-6 (적격성 테스트) | 전체 빌드 — SWE-6 적격성 테스트 대상 바이너리 |
| SPL2-BUILD-0010 | SPL2-REL-0001 (출시 노트) | Release 바이너리 — 릴리스 패키지 대상 |

---

## 5. 변경 이력

| 버전 | 날짜 | 변경 내역 | 작성자 |
|------|------|---------|--------|
| v1.0 | 2026-04-05 | 최초 작성 — 빌드 환경 및 활동 10개 정의 | ASPICE SPL-2 전문가 |
