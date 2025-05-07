#include "FileSystemUtils.h"
#include "Directory.h"
#include "File.h"
#include <iostream>
#include <typeinfo>

void findAndPrintFiles(const FileSystemElement* element) {
    if (const Directory* dir = dynamic_cast<const Directory*>(element)) {
        for (const auto& child : dir->getElements()) {
            findAndPrintFiles(child.get());
        }
    } else if (const File* file = dynamic_cast<const File*>(element)) {
        std::cout << "Found file: " << file->getName() << "\n";
    } else {
        std::cout << "Unknown element type: " << typeid(*element).name() << "\n";
    }
}

const FileSystemElement* findElementByName(const Directory* dir, const std::string& name) {
    for (const auto& elem : dir->getElements()) {
        if (elem->getName() == name) {
            return elem.get();
        }

        if (const Directory* subdir = dynamic_cast<const Directory*>(elem.get())) {
            if (const FileSystemElement* found = findElementByName(subdir, name)) {
                return found;
            }
        }
    }
    return nullptr;
}

std::sort(elements.begin(), elements.end(),
    [](const std::unique_ptr<FileSystemElement>& a, const std::unique_ptr<FileSystemElement>& b) {
        return a->getName() < b->getName();
    }
);