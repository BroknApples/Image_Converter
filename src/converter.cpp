#include "converter.hpp"

/****************************************************************/
/**************************** PRIVATE ***************************/
/****************************************************************/

Converter::ConversionMethods Converter::getConversionType(std::string_view str) {
  if (str == "png") {
    return ConversionMethods::PNG;
  }
  else {
    return ConversionMethods::CONVERSION_COUNT;
  }
}

/****************************************************************/
/**************************** PUBLIC ****************************/
/****************************************************************/

Converter::Converter()
{
  running = true;

  // image data
  src_file_ = "";
  width_ = 0;
  height_ = 0;
  rgba_data_ = 0;
  buffer_ = {};
  stream_size_ = 0;
}

/**
 * @brief Get raw data from a given source file.
 *        Use in combination with decode & encode.
 * 
 * @param input_file: source file
 * 
 * @return True/False of the function's success
 */
bool Converter::getRawData(const std::string& input_file) {
  src_file_ = fs::current_path() / fs::path(input_file);

  std::cout << "[System] Getting raw data for file: " << src_file_ << "\n";

  // Open the input file
  std::ifstream rfile(src_file_, std::ios::binary | std::ios::ate);
  if (!rfile.is_open()) {
    std::cerr << "[Error] Could not open source file: " << src_file_ << std::endl;
    return false;
  }

  // Read file into buffer
  stream_size_ = rfile.tellg();
  buffer_ = std::vector<uint8_t>(stream_size_);

  rfile.seekg(0, std::ios::beg);
  if (!rfile.read(reinterpret_cast<char*>(buffer_.data()), stream_size_)) {
    std::cerr << "[Error] Could not read input file: " << src_file_ << std::endl;
    return false;
  }

  rfile.close();
  return true;
}

/**
 * @brief Decode a image using it's raw data
 *        Use in combination with getRawData & encode.
 */
bool Converter::decode(const std::string& type) {
  ConversionMethods method = getConversionType(type);

  switch(method) {
    case WEBP:
      rgba_data_ = WebPDecodeRGBA(buffer_.data(), stream_size_, &width_, &height_);
      break;
    case PNG:
      // decode png
      break;
  }

  return true;
}

/**
 * @brief Encode an image using it's raw data.
 *        Use in combination with getRawData & decode.
 */
bool Converter::encode(const std::string& type) {
  ConversionMethods method = getConversionType(type);

  switch(method) {
    case WEBP:
      // TODO: if (!write_webp()) return false;
      break;
    case PNG:
      // TODO: if (!stbi_write_png(img_data_)) return false;
      break;
  }
  
  return true;
}