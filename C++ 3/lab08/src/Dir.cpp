#include "Dir.h"
#include "File.h"
#include "Link.h"
#include <iostream>
#include <typeinfo>

Dir::Dir(const std::string& name)
    : name(name), permissions(0777), modDate("2024-12-31") {}

void Dir::add(std::unique_ptr<FileSystemElement> element) {
    elements.push_back(std::move(element));
}

void Dir::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Dir: " << name << "\n";
    for (const auto& elem : elements) {
        elem->print(os, indent + 2);
    }
}

void Dir::printInfo() const {
    std::cout << "Katalog: " << name << ", prawa: " << permissions
              << ", rozmiar: " << getSize()
              << ", modyfikacja: " << modDate << "\n";
}

void Dir::printElementsInfo() const {
    for (const auto& elem : elements) {
        if (auto f = dynamic_cast<File*>(elem.get())) {
            f->printInfo();
        } else if (auto d = dynamic_cast<Dir*>(elem.get())) {
            d->printInfo();
        } else if (auto l = dynamic_cast<Link*>(elem.get())) {
            l->printInfo();
        } else {
            std::cout << "Nieznany typ: " << typeid(*elem).name() << "\n"; // elem->getType()
        }
    }
}

void Dir::ls() const {
    std::cout << "Zawartość katalogu '" << name << "':\n";
    for (const auto& elem : elements) {
        std::cout << "- " << elem->getName()
                  << " (" << typeid(*elem).name()
                  << "), prawa: " << elem->getPermissions() << "\n";
    }
}

const std::string& Dir::getName() const { return name; }

const std::string& Dir::getType() const {
    static std::string type = "Dir";
    return type;
}

void Dir::setPermissions(int p) { permissions = p; }

int Dir::getPermissions() const { return permissions; }

int Dir::getSize() const {
    int sum = 0;
    for (const auto& elem : elements) {
        sum += elem->getSize();
    }
    return sum;
}

const std::string& Dir::getModificationDate() const { return modDate; }

const std::vector<std::unique_ptr<FileSystemElement>>& Dir::getElements() const {
    return elements;
}

std::ostream& operator<<(std::ostream& os, const Dir& dir) {
    dir.print(os, 0);
    return os;
}