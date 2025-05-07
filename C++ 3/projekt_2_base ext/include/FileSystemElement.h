#pragma once
#include <iostream>
#include <string>

class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;
    virtual void print(std::ostream& os, int indent = 0) const = 0;
    virtual const std::string& getName() const = 0;
};