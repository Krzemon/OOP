#include "Directory.h"

Directory::Directory(const std::string& name) : name(name) {}

void Directory::addElement(std::unique_ptr<FileSystemElement> element) {
    elements.push_back(std::move(element));
}

const std::vector<std::unique_ptr<FileSystemElement>>& Directory::getElements() const {
    return elements;
}

void Directory::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Dir: " << name << "\n";
    for (const auto& elem : elements) {
        elem->print(os, indent + 2);
    }
}

const std::string& Directory::getName() const {
    return name;
}