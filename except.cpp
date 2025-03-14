#include "except.h"
#include <exception>
#include <iostream>

namespace Except {

void react() {
  try {
    throw;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Caught unknown exception" << std::endl;
  }
}

} // namespace Except
