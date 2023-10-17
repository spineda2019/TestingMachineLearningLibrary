#include <iostream>

#include "Matrix.h"

bool test_vector_constructor() {
  try {
    // Good
    std::vector<std::vector<int>> data{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
  } catch (BadDataConstructorException& e) {
    std::cout << "Unexpected CTOR failure: Test 1 failed" << std::endl;
    return false;
  }

  try {
    // Bad
    std::vector<std::vector<int>> bad_data{{0, 0, 0}, {0, 0}, {0}};
    tensor_math::Matrix<int> bad_test = tensor_math::Matrix<int>(bad_data);
  } catch (BadDataConstructorException& e) {
    std::cout << "Successfuly caught expected exception: Test 1 passed"
              << std::endl;
    return true;
  }
}

/**
 * @brief Main Test Suite for ML Library
 * @return 0 if all tests succeed, somthing less than 0 otherwise
 */
int main() {
  bool test_1 = test_vector_constructor();
  bool all_tests_passed = test_1;

  if (all_tests_passed) {
    std::cout << "All tests passed!" << std::endl;
  } else {
    std::cout << "Some tests failed..." << std::endl;
  }
}