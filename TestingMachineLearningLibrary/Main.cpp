#include <iostream>
#include "Matrix.h"

/**
 * @brief Main Test Suite for ML Library
 * @return 0 if all tests succeed, somthing less than 0 otherwise
 */
int main() {
  int err_code = 0;

  tensor_math::Matrix<int> test = tensor_math::Matrix<int>();
  std::cout << test.GetRows() << std::endl;
  std::cout << "Error Code: " << err_code << std::endl;
  return 0;
}