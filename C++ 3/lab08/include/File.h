#pragma once
#include "FileSystemElement.h"

class File : public FileSystemElement {
    std::string name; // nazwa pliku
    int permissions; // uprawnienia
    int size; // rozmiar 
    std::string modDate; // data modyfikacji
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
     * @brief metoda wypisująca informacje o pliku
     */
    void printInfo() const override;
    /**
     * @brief metoda listująca nazwe pliku
     */
    void ls() const override;
    /**
     * @brief metoda zwracająca nazwę pliku
     */
    const std::string& getName() const override;
    /**
     * @brief metoda zwracająca typ pliku
     */
    const std::string& getType() const override;
    /**
     * @brief metoda ustawiająca uprawnienia pliku
     */
    void setPermissions(int permissions) override;
    /**
     * @brief metoda zwracająca uprawnienia pliku
     */
    int getPermissions() const override;
    /**
     * @brief metoda zwracająca rozmiar pliku
     */
    int getSize() const override;
    /**
     * @brief metoda zwracająca datę modyfikacji pliku
     */
    const std::string& getModificationDate() const override;
};