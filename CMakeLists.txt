cmake_minimum_required(VERSION 3.16)

project(calculator
    VERSION 1.0.0
    DESCRIPTION "CLI 계산기 소프트웨어 — ASPICE SWE-1~SWE-6"
    LANGUAGES CXX
)

# ─────────────────────────────────────────────
# 언어 표준 설정 (SPL2-BUILD-0001 §1.4)
# ─────────────────────────────────────────────
set(CMAKE_C_STANDARD   11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────────
# 빌드 타입 기본값
# ─────────────────────────────────────────────
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug|Release)" FORCE)
endif()

# ─────────────────────────────────────────────
# 공통 컴파일 옵션 (SPL2-BUILD-0001 §1.4)
# ─────────────────────────────────────────────
add_compile_options(-Wall -Wextra)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Debug 전용: 커버리지 플래그 (SPL2-FEAT-0012)
    add_compile_options(-g -O0 --coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O2 -DNDEBUG)
endif()

# ─────────────────────────────────────────────
# include 경로 (SPL2-BUILD-0001 §1.2)
# ─────────────────────────────────────────────
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

# ─────────────────────────────────────────────
# calc_lib 정적 라이브러리 (SWE-UNIT-0001~0004)
# ─────────────────────────────────────────────
add_library(calc_lib STATIC
    src/Calculator.cpp
    src/InputParser.cpp
    src/AppController.cpp
)
target_include_directories(calc_lib PUBLIC ${PROJECT_SOURCE_DIR}/src)

# ─────────────────────────────────────────────
# 실행 파일 (SWE3-UNIT-SPEC-0001 §5)
# ─────────────────────────────────────────────
add_executable(calculator
    src/main.cpp
)
target_link_libraries(calculator PRIVATE calc_lib)

# ─────────────────────────────────────────────
# Google Test 연동 (SPL2-FEAT-0011, SPL2-BUILD-0005)
# BUILD_TESTING=ON 일 때만 활성화
# ─────────────────────────────────────────────
option(BUILD_TESTING "단위 테스트 빌드 활성화 (Debug 권장)" ON)

if(BUILD_TESTING)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0   # 버전 고정 (SPL2-BUILD-0001 §3 재현성)
    )
    # Windows: gtest의 /MD-/MT 충돌 방지
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # tests/ 디렉터리가 존재할 때만 포함
    if(EXISTS ${PROJECT_SOURCE_DIR}/tests/CMakeLists.txt)
        add_subdirectory(tests)
    endif()
endif()
