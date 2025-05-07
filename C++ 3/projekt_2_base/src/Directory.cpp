#include "Directory.h"

Directory::Directory(const std::string& name) : name(name) {}

void Directory::addElement(std::unique_ptr<FileSystemElement> element) {
    elements.push_back(std::move(element));
}

void Directory::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Dir: " << name << std::endl;
    for (const auto& element : elements) {
        element->print(os, indent + 2);
    }
}