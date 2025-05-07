#pragma once
#include <string>
#include <iostream>

class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;
    virtual void print(std::ostream& os, int indent = 0) const = 0;
    virtual void printInfo() const = 0;
    virtual void ls() const = 0;
    virtual const std::string& getName() const = 0;
    virtual const std::string& getType() const = 0;
    virtual void setPermissions(int permissions) = 0;
    virtual int getPermissions() const = 0;
    virtual int getSize() const = 0;
    virtual const std::string& getModificationDate() const = 0;
};