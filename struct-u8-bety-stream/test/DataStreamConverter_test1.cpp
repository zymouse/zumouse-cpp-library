#include "../data_stream_converter.hpp"
struct Demo01
{
    std::array<uint8_t, 2> message_head = {'@', '<'};        ///<  消息头  byte类型 @ < 40 3c 
    std::string message_body="";              ///<  消息体 字符串类型

    Demo01() = default;
    // operator std::vector<uint8_t>() const;
    // Demo01& operator=(const std::vector<uint8_t>& byte_stream);
};
template <typename T> uint16_t getStoreByteSize1(const T &data) {
  if constexpr (std::is_same_v<T, std::string>) {
    return 0;
  }
  
  if constexpr (std::is_same_v<T, std::vector<uint8_t>> ||
                is_std_array_of_uint8<T>::value) {
    return data.size();
  } else if constexpr (std::is_fundamental<T>::value) {
    return sizeof(data);
  } else {
    std::cerr << "[getStoreByteSize1]不是基础类型, std::vector<uint8_t>, "
                 "string, array<uint8_t, N>:"
              << typeid(T).name()
              << std::endl;
    return 0xffff;
  }
  return 0xffff;
}
uint16_t get_struct_non_string_size(const Demo01 &struct_data) {
  std::uint16_t struct_size = 0;
  struct_size = struct_size + getStoreByteSize1(struct_data.message_head);
  struct_size = struct_size + getStoreByteSize1(struct_data.message_body);
  return struct_size;
}


int main() {
  std::vector<uint8_t> byteStream;
  Demo01 demo01;
  demo01.message_body = "ABC";

  std::cout << "stringVar1——size():" << getStoreByteSize1(demo01.message_body) << std::endl;
  
  get_struct_non_string_size(demo01);
  std::cout << "-----------" << std::endl;


  // std::cout << "\narray<uint8_t,N>-----------"  << std::endl;
  // std::array<uint8_t, 5> arr1 = {'A', 'B', 'C', 'D', 'E'};
  // std::array<uint8_t, 2> arr2 = {'A', 'B'};

  // byteStream.clear();
  // storeToByteStreamBigEndian(arr1, byteStream);
  // show(byteStream);

  // storeToByteStreamBigEndian(arr2, byteStream);
  // show(byteStream);

  // std::array<uint8_t, 3> arr3;
  // storeFromByteStreamBigEndian(arr3, byteStream);
  // show(arr3);
  // std::cout << "-----------"  << std::endl;

  return 0;
}

// g++ DataStreamConverter_test1.cpp -o DataStreamConverter_test1.exe
