#include "File.h"
#include <iostream>

File::File(const std::string& name): FileSystemElement(name) {}

void File::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "File: " << name << "\n";
}

const std::string& File::getName() const { return name; }
