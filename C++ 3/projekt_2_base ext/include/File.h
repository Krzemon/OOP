#pragma once
#include "FileSystemElement.h"

class File : public FileSystemElement {
private:
    std::string name;

public:
    explicit File(const std::string& name);

    void print(std::ostream& os, int indent = 0) const override;
    const std::string& getName() const override;
};