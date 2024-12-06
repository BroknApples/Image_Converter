#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <fstream>
#include <vector>

// my includes in the CMakeLists.txt not working, using full paths for now.
#include "../include/libwebp-1.4.0-windows-x64/include/webp/decode.h"
#include "../include/stb/stb_image_write.h"

/**
 * @brief holds the raw data of an image file
 */
struct ImgData {
  ImgData() : filename("NULL"), width(0), height(0), rgbaData(nullptr) {}
  ImgData(std::string filename, int width, int height, uint8_t* data) : filename(filename), width(width), height(height), rgbaData(rgbaData) {}

  std::string filename; // basename - no extension
  int width, height;
  uint8_t* rgbaData;
};

enum ConversionMethods {
  WEBP,
  PNG,
  CONVERSION_COUNT
};

class Converter {
 private:
  ConversionMethods src_;
  ConversionMethods dst_;
  ImgData raw_data_;

  /***************** Conversion methods *****************/
  void getRawData();
  // Decode
  bool getWebpData();
  // Encode

 public:
  Converter(ConversionMethods src, ConversionMethods dst) : src_(src), dst_(dst) {}

  bool decode();
  bool encode();
};

#endif // CONVERTER_HPP




// need to rethink this
/*
ok we take conversion types as an argument, we pass each and every single file through a check to see if it
is part of the files that should be converted : could use a hashmap or something for this

okokok
now we need to handle the file if and only if it is a valid file
buttt, converter will only recieve a filename if it passes a check in the cms class
*/