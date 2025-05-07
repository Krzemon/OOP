#pragma once
#include "FileSystemElement.h"
#include <vector>
#include <memory>

class Dir : public FileSystemElement {
    std::string name; // nazwa katalogu
    int permissions; // uprawnienia
    std::vector<std::unique_ptr<FileSystemElement>> elements; // elementy katalogu
    std::string modDate; // data modyfikacji
public:
    /**
     * @brief Konstruktor klasy Dir
     */
    Dir(const std::string& name);
    /**
     * @brief metoda dodająca element do katalogu
     */
    void add(std::unique_ptr<FileSystemElement> element);
    /**
     * @brief metoda wypisująca całą strukturę katalogów i plików
     */
    void print(std::ostream& os, int indent = 0) const override;
    /**
     * @brief metoda wypisująca informacje o katalogu
     */
    void printInfo() const override;
    /**
     * @brief metoda wypisująca informacje o elementach katalogu
     */
    void printElementsInfo() const;
    /**
     * @brief metoda listująca zawartość katalogu
     */
    void ls() const override;

    /**
     * @brief metoda zwracająca nazwę katalogu
     */
    const std::string& getName() const override;
    /**
     * @brief metoda zwracająca typ katalogu
     */
    const std::string& getType() const override;
    /**
     * @brief metoda ustawiająca uprawnienia katalogu
     */
    void setPermissions(int permissions) override;
    /**
     * @brief metoda zwracająca uprawnienia katalogu
     */
    int getPermissions() const override;
    /**
     * @brief metoda zwracająca rozmiar katalogu
     */
    int getSize() const override;
    /**
     * @brief metoda zwracająca datę modyfikacji katalogu
     */
    const std::string& getModificationDate() const override;
    /**
     * @brief metoda zwracająca elementy katalogu
     */
    const std::vector<std::unique_ptr<FileSystemElement>>& getElements() const;
};

/**
 * @brief operator << do wypisywania katalogu
 */
std::ostream& operator<<(std::ostream& os, const Dir& dir);