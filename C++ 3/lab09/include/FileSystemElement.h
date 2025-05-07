#pragma once
#include <string>
#include <iostream>

class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;
    virtual void print(std::ostream& os, int indent = 0) const = 0;
    virtual const std::string& getName() const = 0;
protected:
    std::string name; // nazwa katalogu

    FileSystemElement(const std::string& name): name(name) {}
};