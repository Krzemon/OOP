#pragma once
#include "File.h"

class Link : public File {
    FileSystemElement* target; // wskaźnik do elementu docelowego
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
     * @brief metoda zwracająca nazwę dowiązania
     */
    const std::string& getName() const override;
    /**
     * @brief metoda zwracająca element docelowy
     */
    FileSystemElement* getTarget() const { return target; }

};