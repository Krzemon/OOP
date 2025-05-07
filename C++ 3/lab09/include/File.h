#pragma once
#include "FileSystemElement.h"

class File : public FileSystemElement {
    int size; // rozmiar 

public:
    /**
     * @brief Konstruktor klasy File
     */
    File(const std::string& name);
    /**
     * @brief metoda do ustawiania uprawnień
     */
    void print(std::ostream& os, int indent = 0) const override;
    /**
     * @brief metoda zwracająca nazwę pliku
     */
    const std::string& getName() const override;
};