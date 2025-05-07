#pragma once
#include "FileSystemElement.h"
#include <string>

class File : public FileSystemElement {
private:
    std::string name;

public:
    explicit File(const std::string& name);
    void print(std::ostream& os, int indent) const override;
};