#include "Link.h"
#include <iostream>

Link::Link(const std::string& name, FileSystemElement* target)
    : name(name), target(target), permissions(0666), modDate("2025-05-05") {}

void Link::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "[LINK]: " << name;
    if (target)
        os << " -> " << target->getName();
    else
        os << " -> (null)";
    os << "\n";
}

const std::string& Link::getName() const { return name; }