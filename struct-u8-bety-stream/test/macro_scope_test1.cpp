#include "../macro_scope.hpp"
namespace sendMessage{
struct SendMessage
{
    uint16_t header=0x5AA5;
    uint16_t version=0x2001;
    uint64_t timestamp=0;
    uint16_t device_type=0x0001;
    int device_id=1234567;
    uint8_t data_direction=0x1;
    uint8_t data_type=0x1;
    uint8_t encryption_type=0x0;
    uint32_t reserved=0xffffffff;
    uint16_t message_length=0;
    std::string message_body;
    uint16_t check_code=0x0005;
    SendMessage() = default;
    operator std::vector<uint8_t>() const;
    SendMessage& operator=(const std::vector<uint8_t>& byte_stream);
};

PIXMOVING_SERDE_BS_STRUCT(SendMessage,header,version,timestamp,device_type,device_id,data_direction,data_type,
                                encryption_type,reserved,message_length,message_body,check_code);
}

namespace receiveMessage{
struct ReceiveMessage
{
    uint16_t header;
    uint16_t version;
    uint64_t timestamp;
    uint16_t device_type;
    int device_id;
    uint8_t data_direction;
    uint8_t data_type;
    uint8_t encryption_type;
    uint32_t reserved;
    uint16_t message_length;
    std::string message_body;
    uint16_t check_code;
    ReceiveMessage() = default;
    operator std::vector<uint8_t>() const;
    ReceiveMessage& operator=(const std::vector<uint8_t>& byte_stream);
};

PIXMOVING_SERDE_BS_STRUCT(ReceiveMessage,header,version,timestamp,device_type,device_id,data_direction,data_type,
                                encryption_type,reserved,message_length,message_body,check_code);
}

int main()
{
    sendMessage::SendMessage demo01;
    receiveMessage::ReceiveMessage demo02;

    demo01.message_body = "ABCD";
    demo01.message_length = demo01.message_body.size();
    
    demo02.message_body = "EFHJ";
    demo02.message_length = demo01.message_body.size();

    std::vector<uint8_t> byte_stream_data01;
    std::vector<uint8_t> byte_stream_data02;

    byte_stream_data01 = demo01;
    byte_stream_data02 = demo02;
    show(byte_stream_data01);
    show(byte_stream_data02);

    demo01 = byte_stream_data01;
    demo02 = byte_stream_data02;
    std::cout << demo01.message_body << std::endl;
    std::cout << demo02.message_body << std::endl;
    return 0;
}
// g++ macro_scope_test1.cpp -o macro_scope_test1.exe
