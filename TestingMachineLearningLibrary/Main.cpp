#include <iostream>

#include "Matrix.h"

bool test_vector_constructor() {
  try {
    // Good
    std::vector<std::vector<int>> data{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
  } catch (BadDataConstructorException& e) {
    std::cout << "Unexpected CTOR failure: Test 1 failed" << std::endl;
    std::cerr << e.what() << std::endl;
    return false;
  }

  try {
    // Bad
    std::vector<std::vector<int>> bad_data{{0, 0, 0}, {0, 0}, {0}};
    tensor_math::Matrix<int> bad_test = tensor_math::Matrix<int>(bad_data);
  } catch (BadDataConstructorException& e) {
    std::cout << "Successfuly caught expected exception: Test 1 passed"
              << std::endl;
    std::cerr << e.what() << std::endl;
    return true;
  }
}

bool test_stream_print() {
  try {
    std::vector<std::vector<int>> data{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    std::cout << test << std::endl;
    std::cout << "Succesful printing (Verify Visually): Test 2 passed"
              << std::endl;
    return true;
  } catch (std::exception& e) {
    std::cout << "Unexpected printing error: Test 2 failed" << std::endl;
    std::cerr << e.what() << std::endl;
    return false;
  }
}

bool test_rhs_multiply() {
  try {
    std::vector<std::vector<int>> data{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    std::cout << test << std::endl;
    std::cout << "Multiplying by 2.0f with matrix on rhs..." << std::endl;
    std::cout << 2.0f * test << std::endl;
    std::cout
        << "3x3 unit matrix RHS multiplication (check visually): Test 3 passed!"
        << std::endl;
    return true;
  } catch (std::exception& e) {
    std::cout
        << "Unexpected Right Hand Side multiplication error: Test 3 failed"
        << std::endl;
    std::cerr << e.what() << std::endl;
    return false;
  }
}

bool test_lhs_multiply() {
  try {
    std::vector<std::vector<int>> data{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    std::cout << test << std::endl;
    std::cout << "Multiplying by 2.0f with matrix on lhs..." << std::endl;
    std::cout << test * 2.0f << std::endl;
    std::cout
        << "3x3 unit matrix LHS multiplication (check visually): Test 3 passed!"
        << std::endl;
    return true;
  } catch (std::exception& e) {
    std::cout
        << "Unexpected Left Hand Side multiplication error: Test 3 failed"
        << std::endl;
    std::cerr << e.what() << std::endl;
    return false;
  }
}

/**
 * @brief Main Test Suite for ML Library
 * @return 0 if all tests succeed, somthing less than 0 otherwise
 */
int main() {
  bool test_1 = test_vector_constructor();
  bool test_2 = test_stream_print();
  bool test_3 = test_rhs_multiply();
  bool test_4 = test_lhs_multiply();
  bool all_tests_passed = test_1 && test_2 && test_3 && test_4;

  if (all_tests_passed) {
    std::cout << "All tests passed!" << std::endl;
  } else {
    std::cout << "Some tests failed..." << std::endl;
  }
}