#include "../macro_scope.hpp"

struct Demo01
{
    std::array<uint8_t, 2> message_head = {'@', '<'};        ///<  消息头  byte类型 @ < 40 3c 
    std::string message_body="";              ///<  消息体 字符串类型

    Demo01() = default;
    operator std::vector<uint8_t>() const;
    Demo01& operator=(const std::vector<uint8_t>& byte_stream);
};


PIXMOVING_SERDE_BS_STRUCT(Demo01, message_head, message_body)
// g++ -E macro_scope_test.cpp -o macro_scope_test.i


int main()
{
    Demo01 demo01;
    demo01.message_body = "ABC";
    std::vector<uint8_t> byte_stream_data;
    byte_stream_data = demo01;
    show(byte_stream_data);

    byte_stream_data[2] = 'B';
    demo01 = byte_stream_data;
    std::cout << demo01.message_body << std::endl;
    return 0;
}

// g++ macro_scope_test.cpp -o macro_scope_test.exe