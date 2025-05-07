#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H

#include <iostream>
#include <functional>
#include <vector>
#include <iostream>
#include <string>

class StringProcessor {
private:
    std::vector<std::function<void(std::string&)>> voidAlgorithms;
    std::vector<std::function<int(std::string&)>> intAlgorithms;

    bool _reverseEnabled = false;
    int _last_result = 0;
public:
    StringProcessor() = default;
    ~StringProcessor() = default;

    /**
     * Dodaje algorytm ktory zwraca void
     */
    void addVoidAlgorithm(std::function<void(std::string&)> func);
    /**
     * Dodaje algorytm ktory zwraca int
     */
    void addIntAlgorithm(std::function<int(std::string&)> func);
    /**
     * Przetwarzanie napis za pomocą przeciążonego operatora ()
     */
    void operator()(std::string& text);
    /**
     * Resetuje przetwarzanie
     */
    void reset();
    /**
     * Aktywuje wbudowany algorytm 
     */
    void enableAlgorithm(std::string&& text);
};

#endif // STRINGPROCESSOR_H