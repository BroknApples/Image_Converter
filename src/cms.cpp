#include "cms.hpp"

/*******************************************************************
****************************** PRIVATE *****************************
*******************************************************************/

/**
 * 
 */
void CMS::prompt() {

}

/**
 * 
 */
bool CMS::checkValidFile(const auto& std::filesystem::path file) {
  std::string extension == file.extension().string();
  ConversionMethods filetype = convertToKey(extension);

  for (const auto& pair : filetype) {
    if (typeid(extension == ConversionMethods) && pair.first == extension);
  }

  return false;
}

/**
 * 
 */
ConversionMethods CMS::convertToKey(std::string& extension) {
  if (extension == "png") {
    return ConversionMethods::PNG;
  }
  else if (extension == "webp") {
    return ConversionMethods::WEBP;
  }

  return ConversionMethods::CONVERSION_COUNT;
}

/**
 * 
 */
void CMS::listConversionMethods() {
  std::cout << "Conversion Methods: " << std::endl;
  for (const auto& pair : conversion_methods_) {
    std::cout << pair.first << " -> " << pair.second << "\n";
  }
}


/*******************************************************************
****************************** PUBLIC ******************************
*******************************************************************/

/**
 * 
 */
void CMS::run() {
  
}
