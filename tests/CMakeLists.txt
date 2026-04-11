cmake_minimum_required(VERSION 3.16)

# ─────────────────────────────────────────────
# 단위 테스트 타겟 (SWE-4, SWE-TC-0001~0023)
# ─────────────────────────────────────────────

# Calculator 단위 테스트 (SWE-TC-0001~0008)
add_executable(test_calculator
    unit/test_calculator.cpp
)
target_link_libraries(test_calculator PRIVATE
    calc_lib
    GTest::gtest_main
)
target_include_directories(test_calculator PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

# InputParser 단위 테스트 (SWE-TC-0009~0023)
add_executable(test_inputparser
    unit/test_inputparser.cpp
)
target_link_libraries(test_inputparser PRIVATE
    calc_lib
    GTest::gtest_main
)
target_include_directories(test_inputparser PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

# ─────────────────────────────────────────────
# 통합 테스트 타겟 (SWE-5, SWE-ITC-0001~0013)
# ─────────────────────────────────────────────

add_executable(test_integration
    integration/test_integration.cpp
)
target_link_libraries(test_integration PRIVATE
    calc_lib
    GTest::gtest_main
)
target_include_directories(test_integration PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

# CTest 자동 등록
include(GoogleTest)
gtest_discover_tests(test_calculator)
gtest_discover_tests(test_inputparser)
gtest_discover_tests(test_integration)
