// A simple program that computes the square root of a number
#include <iostream>
#include <string>

#include "tutorial/MathFunctions.h"
#include "tutorial/TutorialConfig.h"

int main()
{
    // report version
    std::cout << "Tutorial Library Version: " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;

  // convert input to double
  const double inputValue = 36;

  const double outputValue = mathfunctions::sqrt(inputValue);

  if (outputValue == 6.0) {
  std::cout << "The square root of " << inputValue << " is " << outputValue << ". Test passed."
            << std::endl;
  }
  else {
      std::cout << "Test failed. The square root should have been 6.0, while it ended up being: " << outputValue << std::endl;

  }
  return 0;
}
