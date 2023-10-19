#include <iostream>

#include "Matrix.h"

bool test_vector_constructor() {
  std::cout << "TEST 1:" << std::endl;
  try {
    // Good
    std::vector<std::vector<int>> data{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
  } catch (BadDataConstructorException& e) {
    std::cout << "Unexpected CTOR failure: Test 1 failed" << std::endl;
    std::cerr << "Caught Error: " << e.what() << std::endl;
    return false;
  }

  try {
    // Bad
    std::vector<std::vector<int>> bad_data{{0, 0, 0}, {0, 0}, {0}};
    tensor_math::Matrix<int> bad_test = tensor_math::Matrix<int>(bad_data);
  } catch (BadDataConstructorException& e) {
    std::cerr << "Caught Error: " << e.what() << std::endl;
    std::cout << "Successfuly caught expected exception: Test 1 passed"
              << std::endl;
    return true;
  }
}

bool test_stream_print() {
  std::cout << "TEST 2:" << std::endl;
  try {
    std::vector<std::vector<int>> data{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    std::cout << test << std::endl;
    std::cout << "Succesful printing (Verify Visually): Test 2 passed"
              << std::endl;
    return true;
  } catch (std::exception& e) {
    std::cout << "Unexpected printing error: Test 2 failed" << std::endl;
    std::cerr << "Caught Error: " << e.what() << std::endl;
    return false;
  }
}

bool test_rhs_multiply() {
  std::cout << "TEST 3:" << std::endl;
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
    std::cerr << "Caught Error: " << e.what() << std::endl;
    return false;
  }
}

bool test_lhs_multiply() {
  std::cout << "TEST 4:" << std::endl;
  try {
    std::vector<std::vector<int>> data{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    std::cout << test << std::endl;
    std::cout << "Multiplying by 2.0f with matrix on lhs..." << std::endl;
    std::cout << test * 2.0f << std::endl;
    std::cout
        << "3x3 unit matrix LHS multiplication (check visually): Test 4 passed!"
        << std::endl;
    return true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Left Hand Side multiplication error: Test 4 failed"
              << std::endl;
    std::cerr << "Caught Error: " << e.what() << std::endl;
    return false;
  }
}

bool test_matrix_multiply() {
  bool success;
  std::cout << "TEST 5:" << std::endl;
  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    tensor_math::Matrix<int> test2 = tensor_math::Matrix<int>(data);

    std::cout << "Squaring below Matrix" << std::endl;
    std::cout << test << std::endl;
    std::cout << test * test2 << std::endl;
    std::cout << "3x3 unit matrix to matrix multiplication (check visually). "
                 "Should be: "
              << std::endl;

    std::cout << "{30 36 42}\n{66 81 96}\n{102 126 150}\n" << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected matrix multiplication error: Test 5 failed"
              << std::endl;
    std::cerr << "Caught Error: " << e.what() << std::endl;
    success = false;
  }

  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> data2{{1, 2, 3}, {4, 5, 6}};

    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    tensor_math::Matrix<int> test2 = tensor_math::Matrix<int>(data2);

    std::cout << "3x3 mat x 2x3 mat should fail" << std::endl;
    std::cout << test * test2 << std::endl;

    std::cout << "Unexpected matrix success: Test 5 failed..." << std::endl;
    success = false;
  } catch (MatrixMultiplicationMismatchException& e) {
    std::cerr << "Caught Error: " << e.what() << std::endl;
    std::cout << "Successfuly caught expected exception: Test 5 passed!"
              << std::endl;
    success = true;
  }

  return success;
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
  bool test_5 = test_matrix_multiply();

  bool all_tests_passed = test_1 && test_2 && test_3 && test_4 && test_5;

  if (all_tests_passed) {
    std::cout << "All tests passed!" << std::endl;
  } else {
    std::cout << "Some tests failed..." << std::endl;
  }
}