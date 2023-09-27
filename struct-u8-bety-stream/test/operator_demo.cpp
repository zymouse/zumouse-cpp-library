#include <iostream>
#include <vector>
#include <cstdint>

struct DEMO {
    int value;
    
    // 定义类型转换操作符
    operator std::vector<uint8_t>() const {
        std::cout << "Executing Function A\n";
        // 在这里实现将 DEMO 对象转换为 std::vector<uint8_t> 的逻辑
        std::vector<uint8_t> byteStream;
        // 以一种方式将 DEMO 对象的信息填充到 byteStream 中
        // 这里仅作为示例，您需要根据实际需求来实现转换逻辑
        byteStream.push_back(static_cast<uint8_t>(value));
        return byteStream;
    }
};

int main() {
    DEMO struct_data;
    struct_data.value = 65; // 假设有这样一个值
    std::vector<uint8_t> byte_stream_data;
    
    // 当我们尝试将 DEMO 类型的对象赋值给 std::vector<uint8_t> 类型时，
    // 定义的类型转换操作符将被调用
    byte_stream_data = struct_data;
    
    return 0;
}


// g++ operator_demo.cpp -o operator_demo.exe
