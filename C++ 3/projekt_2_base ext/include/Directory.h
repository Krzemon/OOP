#pragma once
#include "FileSystemElement.h"
#include <vector>
#include <memory>

class Directory : public FileSystemElement {
private:
    std::string name;
    std::vector<std::unique_ptr<FileSystemElement>> elements;

public:
    explicit Directory(const std::string& name);

    void addElement(std::unique_ptr<FileSystemElement> element);
    const std::vector<std::unique_ptr<FileSystemElement>>& getElements() const;

    void print(std::ostream& os, int indent = 0) const override;
    const std::string& getName() const override;
};