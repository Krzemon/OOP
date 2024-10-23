#include "ProgressBar.h"

ProgressBar::ProgressBar(int total, int length, char symbol) : total(total), length(length), symbol(symbol) {}

void ProgressBar::refresh(int progress) {
    int percent = (progress * 100) / total;
    int pos = (progress * length) / total;

    std::cout << "[";
    for (int i = 0; i < length; ++i) {
        if (i < pos)
            std::cout << symbol;
        else
            std::cout << " ";
    }
    std::cout << "] " << percent << "%\r"; // \r cofa kursor na początek linii
    std::cout.flush();
}

void ProgressBar::setSymbol(char newSymbol) {
    symbol = newSymbol;
}

void ProgressBar::setLength(int newLength) {
    length = newLength;
}