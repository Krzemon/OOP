#include "Directory.h"
#include "File.h"
#include "FileSystemUtils.h"
#include <iostream>

int main() {
    auto root = std::make_unique<Directory>("data");

    root->addElement(std::make_unique<File>("notes.txt"));
    root->addElement(std::make_unique<File>("readme.md"));

    auto img = std::make_unique<Directory>("img");
    img->addElement(std::make_unique<File>("logo.png"));
    img->addElement(std::make_unique<File>("screenshot.jpg"));
    root->addElement(std::move(img));

    auto docs = std::make_unique<Directory>("docs");
    docs->addElement(std::make_unique<File>("manual.pdf"));
    root->addElement(std::move(docs));

    // Wypisanie struktury katalogu
    root->print(std::cout);

    std::cout << "\nWyszukiwanie plików:\n";
    findAndPrintFiles(root.get());

    std::cout << "\nWyszukiwanie elementu 'logo.png':\n";
    const FileSystemElement* found = findElementByName(root.get(), "logo.png");
    if (found) {
        found->print(std::cout);
    } else {
        std::cout << "Nie znaleziono pliku.\n";
    }

    return 0;
}
