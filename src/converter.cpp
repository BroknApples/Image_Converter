#include "converter.hpp"

/*******************************************************************
****************************** PRIVATE *****************************
*******************************************************************/

/**
 * 
 */
void Converter::getRawData() {
  // Open the input file
  std::ifstream file(src_, std::ios::binary | std::ios::ate);
  if (!file.is_open()) {
      std::cerr << "Error: Could not open source file: " << src_ << "\n";
      return false;
  }

  // Read file into buffer
  std::streamsize fileSize = webpFile.tellg();
  webpFile.seekg(0, std::ios::beg);
  std::vector<uint8_t> fileBuffer(fileSize);
  if (!webpFile.read(reinterpret_cast<char*>(fileBuffer.data()), fileSize)) {
      std::cerr << "Error: Could not read input file: " << inputFile << "\n";
      return false;
  }
}

/*******************************************************************
****************************** PUBLIC ******************************
*******************************************************************/

/**
 * 
 */
bool Converter::decode()
{
  switch(src_) {
    case WEBP:
      getWebpData();
      break;
    case PNG:
      getPngData();
  }
  return false;
}

/**
 * 
 */
bool Converter::encode() {
  stbi_write_png()
  return false;
}