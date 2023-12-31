#include <iostream>

#include "Matrix.h"

bool test_vector_constructor() {
  std::cout << "\nTEST 1:" << std::endl;
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
  std::cout << "\nTEST 2:" << std::endl;
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
  std::cout << "\nTEST 3:" << std::endl;
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
  std::cout << "\nTEST 4:" << std::endl;
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
  std::cout << "\nTEST 5:" << std::endl;
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

bool test_matrix_addition() {
  std::cout << "\nTEST 6:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    tensor_math::Matrix<int> test2 = tensor_math::Matrix<int>(data);

    std::cout << "Adding below Matrix to itself" << std::endl;
    std::cout << test << std::endl;
    std::cout << test + test2 << std::endl;

    success = true;
  } catch (MatrixMultiplicationMismatchException& e) {
    std::cout << "Unexpected Addition failure: Test 6 failed..." << std::endl;
    return false;
  }

  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> data2{{1, 2, 3}, {4, 5, 6}};

    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);
    tensor_math::Matrix<int> test2 = tensor_math::Matrix<int>(data2);

    std::cout << "3x3 mat + 2x3 mat should fail" << std::endl;
    std::cout << test + test2 << std::endl;

    std::cout << "Unexpected matrix success: Test 6 failed..." << std::endl;
    return false;
  } catch (MatrixAdditionMismatchException& e) {
    std::cerr << "Caught Error: " << e.what() << std::endl;
    std::cout << "Successfuly caught expected exception: Test 6 passed!"
              << std::endl;
    success = true;
  }

  return success;
}

bool test_sub_matrix() {
  std::cout << "TEST 7:" << std::endl;
  std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);

  std::cout << "Big matrix" << test << std::endl;

  std::cout << "Sub Col 1:" << std::endl;
  std::cout << test.SubSquareMatrix(0) << std::endl;
  std::cout << "Sub Col 2:" << std::endl;
  std::cout << test.SubSquareMatrix(1) << std::endl;
  std::cout << "Sub Col 3:" << std::endl;
  std::cout << test.SubSquareMatrix(2) << std::endl;

  std::vector<std::vector<int>> big_data{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  tensor_math::Matrix<int> big_test = tensor_math::Matrix<int>(big_data);

  std::cout << "Big matrix" << big_test << std::endl;

  std::cout << "Sub Col 1:" << std::endl;
  std::cout << big_test.SubSquareMatrix(0) << std::endl;
  std::cout << "Sub Col 2:" << std::endl;
  std::cout << big_test.SubSquareMatrix(1) << std::endl;
  std::cout << "Sub Col 3:" << std::endl;
  std::cout << big_test.SubSquareMatrix(2) << std::endl;
  std::cout << "Sub Col 4:" << std::endl;
  std::cout << big_test.SubSquareMatrix(3) << std::endl;

  return true;
}

bool test_determinant() { return true; }

bool test_row_scale() {
  std::cout << "\nTEST 8:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);

    std::cout << "Scaling last row of below matrix by 2" << std::endl;
    std::cout << test << std::endl;

    test.ScaleRow(2, 2);

    std::cout << test << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Addition failure: Test 8 failed..." << std::endl;
    return false;
  }

  return success;
}

bool test_add_rows() {
  std::cout << "\nTEST 9:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);

    std::cout << "Adding first two rows and storing in row 3" << std::endl;
    std::cout << test << std::endl;

    test.AddRows(0, 1, 2);

    std::cout << test << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Addition failure: Test 9 failed..." << std::endl;
    return false;
  }

  return success;
}

bool test_subtract_rows() {
  std::cout << "\nTEST 10:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<int>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(data);

    std::cout << "Subtracting first two rows and storing in row 3" << std::endl;
    std::cout << test << std::endl;

    test.SubtractRows(0, 1, 2);

    std::cout << test << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Addition failure: Test 10 failed..." << std::endl;
    return false;
  }

  return success;
}

bool test_empty_matrix() {
  std::cout << "\nTEST 11:" << std::endl;
  try {
    tensor_math::Matrix<int> test = tensor_math::Matrix<int>(3, 3);
    std::cout << "Below Matrix should be empty" << std::endl;
    std::cout << test << std::endl;
    return true;

  } catch (std::exception& e) {
    std::cout << "Test 11 failed..." << std::endl;
    return false;
  }
}

bool test_LU() {
  std::cout << "\nTEST 12:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<float>> data{{1, 1, -1}, {1, -2, 3}, {2, 3, 1}};
    tensor_math::Matrix<float> test = tensor_math::Matrix<float>(data);

    std::cout << "Making LU of matrix:" << std::endl;
    std::cout << test << std::endl;

    std::vector<tensor_math::Matrix<float>> results = test.LU();

    std::cout << "L:" << std::endl;
    std::cout << results[0] << std::endl;

    std::cout << "U:" << std::endl;
    std::cout << results[1] << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Addition failure: Test 12 failed..." << std::endl;
    return false;
  }

  return success;
}

bool test_det() {
  std::cout << "\nTEST 13:" << std::endl;
  bool success;
  try {
    std::vector<std::vector<float>> data{{1, 1, -1}, {1, -2, 3}, {2, 3, 1}};
    tensor_math::Matrix<float> test = tensor_math::Matrix<float>(data);

    std::vector<std::vector<float>> data2{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    tensor_math::Matrix<float> test2 = tensor_math::Matrix<float>(data2);

    std::vector<std::vector<float>> data3{
        {1, 0, 0, 0, 0, 2}, {0, 1, 0, 0, 2, 0}, {0, 0, 1, 2, 0, 0},
        {0, 0, 2, 1, 0, 0}, {0, 2, 0, 0, 1, 0}, {2, 0, 0, 0, 0, 1}};
    tensor_math::Matrix<float> test3 = tensor_math::Matrix<float>(data3);

    std::cout << "Det of matrix:" << std::endl;
    std::cout << test << std::endl;
    std::cout << "is: " << std::endl;
    std::cout << test.Det() << std::endl;

    std::cout << "Det of matrix:" << std::endl;
    std::cout << test2 << std::endl;
    std::cout << "is: " << std::endl;
    std::cout << test2.Det() << std::endl;

    std::cout << "Det of matrix:" << std::endl;
    std::cout << test3 << std::endl;
    std::cout << "is: " << std::endl;
    std::cout << test3.Det() << std::endl;

    success = true;
  } catch (std::exception& e) {
    std::cout << "Unexpected Addition failure: Test 12 failed..." << std::endl;
    return false;
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
  bool test_6 = test_matrix_addition();
  bool test_7 = test_sub_matrix();
  bool test_8 = test_row_scale();
  bool test_9 = test_add_rows();
  bool test_10 = test_subtract_rows();
  bool test_11 = test_empty_matrix();
  bool test_12 = test_LU();
  bool test_13 = test_det();

  bool all_tests_passed =
      test_1 && test_2 && test_3 && test_4 && test_5 && test_6;

  if (all_tests_passed) {
    std::cout << "All tests passed!" << std::endl;
  } else {
    std::cout << "Some tests failed..." << std::endl;
  }
}