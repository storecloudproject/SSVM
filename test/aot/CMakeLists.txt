# SPDX-License-Identifier: Apache-2.0

include(FetchContent)
FetchContent_Declare(
  ssvm_unit_test
  GIT_REPOSITORY https://github.com/second-state/ssvm-unittest.git
  GIT_TAG wasm-1.1
)

FetchContent_GetProperties(ssvm_unit_test)
if(NOT ssvm_unit_test_POPULATED)
  FetchContent_Populate(ssvm_unit_test)
endif()

configure_files(
  ${ssvm_unit_test_SOURCE_DIR}/core
  ${CMAKE_CURRENT_BINARY_DIR}/../core/testSuites
  COPYONLY
)

configure_files(
  ${CMAKE_CURRENT_SOURCE_DIR}/../loader/wagonTestData
  ${CMAKE_CURRENT_BINARY_DIR}/../loader/wagonTestData
  COPYONLY
)

add_executable(ssvmAOTWagonTests
  AOTwagonTest.cpp
)

add_test(ssvmAOTWagonTests ssvmAOTWagonTests)

target_link_libraries(ssvmAOTWagonTests
  PRIVATE
  utilGoogleTest
  ssvmLoader
  ssvmAOT
)

add_executable(ssvmAOTCoreTests
  AOTcoreTest.cpp
)

add_test(ssvmAOTCoreTests ssvmAOTCoreTests)

target_link_libraries(ssvmAOTCoreTests
  PRIVATE
  std::filesystem
  utilGoogleTest
  ssvmTestSpec
  ssvmLoader
  ssvmAOT
  ssvmVM
)
