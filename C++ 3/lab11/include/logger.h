#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Logger {
private:
    Logger() = default;
    ~Logger() = default;

    // nie mozna kopiowac obiektu
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    /**
     * @brief metoda do tworzenia pojedynczego obiektu klasy
     */
    static Logger& get_logger() {
        static Logger instance;
        return instance;
    }

    /**
     * @brief metoda wypisujaca aktualny czas
     */
    std::string current_time() {
        std::time_t result = std::time(nullptr);
        std::string date_time = std::asctime(std::localtime(&result));
        date_time.pop_back();
        return date_time;
    }

    /**
     * @brief metoda wypisujaca log systemowy: czas, adres, napis
     */
    void log(const std::string& str) {
        std::cout << current_time() << " [Logger] " << this << " " << str << std::endl;
    }

};
