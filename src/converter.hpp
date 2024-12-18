#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

// my includes in the CMakeLists.txt not working, using full paths for now.
#include "../include/libwebp-1.4.0-windows-x64/include/webp/decode.h"
#include "../include/stb/stb_image_write.h"

namespace fs = std::filesystem;

class Converter {
 private:
  //**************** BEG Conversion Methods ****************//
  enum ConversionMethods {
    WEBP,
    PNG,
    CONVERSION_COUNT
  };
  //**************** END Conversion Methods ****************//

  bool running;

  // image data
  fs::path src_file_;
  int width_, height_;

  uint8_t* rgba_data_;
  std::vector<uint8_t> buffer_;
  std::streamsize stream_size_;

  ConversionMethods getConversionType(std::string_view str);

 public:
  Converter();

  bool getRawData(const std::string& input_file);
  bool decode(const std::string& type);
  bool encode(const std::string& type);
};

#endif // CONVERTER_HPP