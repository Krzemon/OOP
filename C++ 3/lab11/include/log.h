#pragma once
#include "logger.h"

class Log {
public:
    /**
     * @brief zaawansowany logger
     */
    static void Advanced(const std::string& str) {
        std::cout << Logger::get_logger().current_time() << " [AdvLogger] " << &Logger::get_logger() << " "<< str << std::endl;
    }
// << Logger::get_logger().current_time() 
// 
};
