#pragma once
#include "FileSystemElement.h"
#include <vector>
#include <memory>

class Dir : public FileSystemElement {
    std::vector<std::unique_ptr<FileSystemElement>> elements; // elementy katalogu

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
     * @brief metoda zwracająca nazwę katalogu
     */
    const std::string& getName() const override;
    /**
     * @brief metoda zwracająca elementy katalogu
     */
    std::vector<std::unique_ptr<FileSystemElement>>& getElements();
    /**
    * @brief metoda usuwajaca katalog
    */
    void rm(std::string name, bool removeTarget=false);
};

/**
 * @brief operator << do wypisywania katalogu
 */
std::ostream& operator<<(std::ostream& os, const Dir& dir);