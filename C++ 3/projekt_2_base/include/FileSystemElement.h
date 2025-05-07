#pragma once
#include <iostream>

class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;
    virtual void print(std::ostream& os, int indent) const = 0;
};