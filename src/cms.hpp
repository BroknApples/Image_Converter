/*
  CMS Stands for "Converter Management System"

*/
#ifndef CMS_HPP
#define CMS_HPP

#include <vector>
#include <filesystem>

#include "converter.hpp"

namespace fs = std::filesystem;

class CMS {
 private:
  std::vector<Converter> conversion_methods_;

  // Methods
  void prompt();
  bool checkValidFile(const fs::path& file);
  void listConversionMethods();

 public:
  void run();
};

#endif // CMS_HPP