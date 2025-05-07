#pragma once
#include "FileSystemElement.h"

class Link : public FileSystemElement {
    std::string name; // nazwa dowiązania
    FileSystemElement* target; // wskaźnik do elementu docelowego
    int permissions; // uprawnienia
    std::string modDate; // data modyfikacji
public:
    /** 
     * @brief Konstruktor klasy Link
     */
    Link(const std::string& name, FileSystemElement* target);
    /**
     * @brief metoda wypisująca nazwe dowiązania
     */
    void print(std::ostream& os, int indent = 0) const override;
    /**
     * @brief metoda wypisująca informacje o dowiązaniu
     */
    void printInfo() const override;
    /**
     * @brief metoda listująca nazwe dowiazania
     */
    void ls() const override;

    /**
     * @brief metoda zwracająca nazwę dowiązania
     */
    const std::string& getName() const override;
    /**
     * @brief metoda zwracająca typ dowiązania
     */
    const std::string& getType() const override;
    /**
     * @brief metoda ustawiająca uprawnienia dowiązania
     */
    void setPermissions(int permissions) override;
    /**
     * @brief metoda zwracająca uprawnienia dowiązania
     */
    int getPermissions() const override;
    /**
     * @brief metoda zwracająca rozmiar dowiązania
     */
    int getSize() const override;
    /**
     * @brief metoda zwracająca datę modyfikacji dowiązania
     */
    const std::string& getModificationDate() const override;
};