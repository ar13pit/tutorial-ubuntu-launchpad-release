
#include "tutorial/MathFunctions.h"

#include <cmath>

#ifdef USE_MYMATH
#  include "tutorial/mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
}
}
