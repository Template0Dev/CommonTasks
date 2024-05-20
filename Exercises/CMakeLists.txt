add_executable (Exercises "Entering.cpp" "Entering.h"  "EX22/Polynomial.cpp" "EX22/Polynomial.h" "EX23/Sequence.h" "EX23/Sequence.cpp" "EX24/CharCount.h" "EX24/CharCount.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Exercises PROPERTY CXX_STANDARD 23)
endif()
