#include "../macro_scope.hpp"

// struct Demo01
// {
//     std::array<uint8_t, 2> header;
//     std::array<uint8_t, 2> version;
//     std::array<uint8_t, 8> timestamp;
//     std::array<uint8_t, 2> device_type;
//     // int device_id;
//     std::array<uint8_t, 4> device_id;
//     std::array<uint8_t, 1> data_direction;
//     std::array<uint8_t, 1> data_type;
//     std::array<uint8_t, 1> encryption_type;
//     std::array<uint8_t, 4> reserved;
//     // int message_length;
//     std::array<uint8_t, 4> message_length;
//     std::string message_body;
//     std::array<uint8_t, 2> check_code;

//     Demo01() = default;
//     operator std::vector<uint8_t>() const;
//     Demo01& operator=(const std::vector<uint8_t>& byte_stream);
// };

struct Demo01
{
    uint16_t header=0x5AA5;
    uint16_t version=0x2001;
    uint64_t timestamp=0;
    uint16_t device_type=0x0001;
    int device_id=0x1234;
    uint8_t data_direction=0x1;
    uint8_t data_type=0x1;
    uint8_t encryption_type=0x0;
    uint32_t reserved=0xffffffff;
    int message_length=0;
    std::string message_body;
    uint16_t check_code=0x0005;

    Demo01() = default;
    operator std::vector<uint8_t>() const;
    Demo01& operator=(const std::vector<uint8_t>& byte_stream);
};

PIXMOVING_SERDE_BS_STRUCT(Demo01,header,version,timestamp,device_type,device_id,data_direction,data_type,
                                encryption_type,reserved,message_length,message_body,check_code);
// g++ -E macro_scope_test2.cpp -o macro_scope_test2.i


int main()
{
    Demo01 demo01;
    demo01.message_body = "ABCD";
    demo01.message_length = demo01.message_body.size();
    time_t timep;
    time(&timep);
    demo01.timestamp = static_cast<uint64_t>(timep);

    std::vector<uint8_t> byte_stream_data;
    byte_stream_data = demo01;
    show(byte_stream_data);

    std::cout << "字节流大小：" << std::dec << byte_stream_data.size() << std::endl;
    std::cout << "结构体大小：" <<  get_struct_non_string_size(demo01) << std::endl;
    byte_stream_data[32] = 'C';
    demo01 = byte_stream_data;
    std::cout << demo01.message_body << std::endl;
    return 0;
}
/*
run:
5a a5 20 01 00 00 00 00 65 22 31 9b 00 01 00 00 12 34 01 01 00 ff ff ff ff 00 00 00 04 41 42 43 44 00 05 
字节流大小：35
结构体大小：31
ABCC
*/

// g++ macro_scope_test2.cpp -o macro_scope_test2.exe