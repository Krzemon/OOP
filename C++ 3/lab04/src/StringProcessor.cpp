#include "StringProcessor.h"

void StringProcessor::addVoidAlgorithm(std::function<void(std::string&)> func) {
    voidAlgorithms.push_back(func);
}

void StringProcessor::addIntAlgorithm(std::function<int(std::string&)> func) {
    intAlgorithms.push_back(func);
}

void StringProcessor::operator()(std::string& text) {
    std::cout << "Original string: " << text << std::endl;
    
    for(auto& intFun: intAlgorithms){
        _last_result = intFun(text);
        std::cout << "Result from int algorithms: " << _last_result << std::endl;
    }

    for(auto& voidFun: voidAlgorithms){
        voidFun(text);
    }
    std::cout << "Result from void algorithms: " << text << std::endl;
}

void StringProcessor::reset() {
    _reverseEnabled = false;
    voidAlgorithms.clear();
    intAlgorithms.clear();
    std::cout << "Processor reset. All algorithms removed." << std::endl;
}

void StringProcessor::enableAlgorithm(std::string&& text) {
    if(text == "reverse") {
        std::cout << "Enabling built-in algorithm: reverse" << std::endl;
        _reverseEnabled = true;
        voidAlgorithms.push_back([](std::string& str) {
            std::reverse(str.begin(), str.end());
        });
    }
}
