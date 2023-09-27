#include "../data_stream_converter.hpp"

int main() {
  std::vector<uint8_t> byteStream;

  // 存储 int 类型变量
  std::cout << "\nint-----------"  << std::endl;

  byteStream.clear();
  int intVar = 0x1234;
  storeToByteStreamBigEndian(intVar, byteStream);
  show(byteStream);

  int intVar1 = 0;
  storeFromByteStreamBigEndian(intVar1, byteStream);
  std::cout << std::hex << "intVar1:0x" << intVar1 << std::endl;
  std::cout << "-----------" << std::endl;

  // 存储 uint64_t 类型变量
  std::cout << "\nint64_t-----------"  << std::endl;

  byteStream.clear();
  uint64_t doubleVar = 0x1234;
  storeToByteStreamBigEndian(doubleVar, byteStream);
  show(byteStream);

  uint64_t doubleVar1 = 0;
  storeFromByteStreamBigEndian(doubleVar1, byteStream);
  std::cout << std::hex << "doubleVar1:0x" << doubleVar1 << std::endl;
  std::cout << "-----------" << std::endl;

  // 存储 string 类型变量
  std::cout << "\nstring-----------"  << std::endl;

  byteStream.clear();
  std::string stringVar = "ABCD"; // 41 42 43 44
  storeToByteStreamBigEndian(stringVar, byteStream);
  show(byteStream);

  std::string stringVar1 = "";
  storeFromByteStreamBigEndian(stringVar1, byteStream);
  std::cout << "stringVar1:" << stringVar1 << std::endl;
  std::cout << "stringVar1——size():" << getStoreByteSize(stringVar1) << std::endl;
  
  std::cout << "-----------" << std::endl;

  // 存储 vector 类型变量
  std::cout << "\nvector-----------"  << std::endl;

  byteStream.clear();
  std::vector<uint8_t> message = {'A', 'B'}; // 41 42
  storeToByteStreamBigEndian(message, byteStream);
  show(byteStream);
  std::vector<uint8_t> message1;
  storeFromByteStreamBigEndian(message1, byteStream);
  show(message1);
  std::cout << "-----------"  << std::endl;


  std::cout << "\narray<uint8_t,N>-----------"  << std::endl;
  std::array<uint8_t, 5> arr1 = {'A', 'B', 'C', 'D', 'E'};
  std::array<uint8_t, 2> arr2 = {'A', 'B'};

  byteStream.clear();
  storeToByteStreamBigEndian(arr1, byteStream);
  show(byteStream);

  storeToByteStreamBigEndian(arr2, byteStream);
  show(byteStream);

  std::array<uint8_t, 3> arr3;
  storeFromByteStreamBigEndian(arr3, byteStream);
  show(arr3);
  std::cout << "-----------"  << std::endl;

  return 0;
}

// g++ DataStreamConverter_test.cpp -o DataStreamConverter_test.exe
