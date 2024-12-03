/*
  CMS Stands for "Converter Management System"

*/
#ifndef CMS_HPP
#define CMS_HPP

#include <array>
#include <memory>

#include "conversion_methods/conversion-methods.hpp"

class CMS {
 private:
  std::array<std::unique_ptr<Converter>, CONVERSION_COUNT> conversion_methods_;
 public:
  void prompt();
  void run();
};

#endif // CMS_HPP