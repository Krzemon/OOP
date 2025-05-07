#include "File.h"
#include <iostream>

File::File(const std::string& name)
    : name(name), permissions(0666), size(1), modDate("2024-12-31") {}

void File::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "File: " << name << "\n";
}

void File::printInfo() const {
    std::cout << "Plik: " << name << ", prawa: " << permissions
              << ", rozmiar: " << size << ", modyfikacja: " << modDate << "\n";
}

void File::ls() const {
    std::cout << "File: " << name << "\n";
}

const std::string& File::getName() const { return name; }

const std::string& File::getType() const {
    static std::string type = "File";
    return type;
}

void File::setPermissions(int p) { permissions = p; }

int File::getPermissions() const { return permissions; }

int File::getSize() const { return size; }

const std::string& File::getModificationDate() const { return modDate; }