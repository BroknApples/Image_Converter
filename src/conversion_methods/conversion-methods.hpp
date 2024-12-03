#ifndef CONVERSION_METHODS_HPP
#define CONVERIONS_METHODS_HPP

#include <array>
#include <string>

#include "webp-to-png.hpp"

enum CONVERSION_METHODS {
  WEBP_TO_PNG,
  CONVERSION_COUNT
};

std::array<std::string, CONVERSION_COUNT> methods = {
  "WEBP To PNG"
};

#endif // CONVERSION_METHODS_HPP