cmake_minimum_required(VERSION 3.16)

project(lab1_swap_ab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14)
    message(WARNING "Требуется GCC >= 14. Обнаружен GCC ${CMAKE_CXX_COMPILER_VERSION}.")
  endif()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(core_swap_ab
  src/swap_ab.cpp
)
target_include_directories(core_swap_ab PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(lab1
  src/main.cpp
)
target_link_libraries(lab1 PRIVATE core_swap_ab)

# -------------------- ТЕСТЫ --------------------
option(USE_SYSTEM_GTEST "Use system-installed GoogleTest if available" ON)

enable_testing()

set(_have_gtest FALSE)

if (USE_SYSTEM_GTEST)
  find_package(GTest QUIET CONFIG)
  if (GTest_FOUND)
    set(_have_gtest TRUE)
  endif()
endif()

if (NOT _have_gtest)
  include(FetchContent)
  set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  # Для устойчивости к изменениям времени распаковки
  set(FETCHCONTENT_QUIET OFF)
  set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  FetchContent_MakeAvailable(googletest)
endif()

add_executable(unit_tests
  tests/swap_ab_test.cpp
)
target_link_libraries(unit_tests PRIVATE core_swap_ab GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)


