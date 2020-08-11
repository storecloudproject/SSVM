# SPDX-License-Identifier: Apache-2.0

add_executable(ssvmCoreTests
  coreTest.cpp
)

add_test(ssvmCoreTests ssvmCoreTests)

target_link_libraries(ssvmCoreTests
  PRIVATE
  std::filesystem
  utilGoogleTest
  ssvmTestSpec
  ssvmVM
)
