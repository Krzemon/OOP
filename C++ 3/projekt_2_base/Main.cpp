#include <iostream>
#include "Directory.h"
#include "File.h"

int main() {
    auto dataDir = std::make_unique<Directory>("data");

    dataDir->addElement(std::make_unique<File>("notes.txt"));
    dataDir->addElement(std::make_unique<File>("readme.md"));

    auto imgDir = std::make_unique<Directory>("img");
    imgDir->addElement(std::make_unique<File>("logo.png"));
    imgDir->addElement(std::make_unique<File>("screenshot.jpg"));
    dataDir->addElement(std::move(imgDir));

    auto docsDir = std::make_unique<Directory>("docs");
    docsDir->addElement(std::make_unique<File>("manual.pdf"));
    dataDir->addElement(std::move(docsDir));

    dataDir->print(std::cout, 0);

    return 0;
}
