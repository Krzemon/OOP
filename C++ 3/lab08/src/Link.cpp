#include "Link.h"
#include <iostream>

Link::Link(const std::string& name, FileSystemElement* target)
    : name(name), target(target), permissions(0666), modDate("2024-12-31") {}

void Link::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Link: " << name << "\n";
}

void Link::printInfo() const {
    std::cout << "Link: " << name << " -> " << target->getName()
              << ", prawa: " << permissions
              << ", modyfikacja: " << modDate << "\n";
}

void Link::ls() const {
    std::cout << "Link: " << name << "\n";
}

const std::string& Link::getName() const { return name; }

const std::string& Link::getType() const {
    static std::string type = "Link";
    return type;
}

void Link::setPermissions(int p) { permissions = p; }

int Link::getPermissions() const { return permissions; }

int Link::getSize() const { return 0; }

const std::string& Link::getModificationDate() const { return modDate; }