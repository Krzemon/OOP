#include "File.h"

File::File(const std::string& name) : name(name) {}

void File::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "File: " << name << std::endl;
}