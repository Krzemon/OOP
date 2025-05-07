#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <typeinfo> // dla typeid
#include <cassert>  // dla assert w przykładzie dynamic_cast

// Bazowa klasa dla elementów systemu plików
class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;

    virtual void print(std::ostream& os, int indent = 0) const = 0;
};

// Klasa reprezentująca plik
class File : public FileSystemElement {
private:
    std::string name;

public:
    File(const std::string& name) : name(name) {}

    void print(std::ostream& os, int indent = 0) const override {
        os << std::string(indent, ' ') << "File: " << name << '\n';
    }

    const std::string& getName() const {
        return name;
    }
};

// Klasa reprezentująca katalog
class Directory : public FileSystemElement {
private:
    std::string name;
    std::vector<std::unique_ptr<FileSystemElement>> elements;

public:
    Directory(const std::string& name) : name(name) {}

    void addElement(std::unique_ptr<FileSystemElement> element) {
        elements.push_back(std::move(element));
    }

    void print(std::ostream& os, int indent = 0) const override {
        os << std::string(indent, ' ') << "Dir: " << name << '\n';
        for (const auto& elem : elements) {
            elem->print(os, indent + 2);
        }
    }

    const std::vector<std::unique_ptr<FileSystemElement>>& getElements() const {
        return elements;
    }
};

// Funkcja pomocnicza - przykład dynamic_cast i typeid
void findAndPrintFiles(const FileSystemElement* element) {
    if (const Directory* dir = dynamic_cast<const Directory*>(element)) {
        // Jeśli to katalog, przechodzimy rekurencyjnie
        for (const auto& child : dir->getElements()) {
            findAndPrintFiles(child.get());
        }
    } else if (const File* file = dynamic_cast<const File*>(element)) {
        // Jeśli to plik, wypisujemy nazwę
        std::cout << "Found file: " << file->getName() << '\n';
    } else {
        // Tutaj używamy typeid jako przykład - powinniśmy nie trafić tutaj
        std::cout << "Unknown type: " << typeid(*element).name() << '\n';
    }
}

// --- Funkcja main ---
int main() {
    auto root = std::make_unique<Directory>("data");

    root->addElement(std::make_unique<File>("notes.txt"));
    root->addElement(std::make_unique<File>("readme.md"));

    auto imgDir = std::make_unique<Directory>("img");
    imgDir->addElement(std::make_unique<File>("logo.png"));
    imgDir->addElement(std::make_unique<File>("screenshot.jpg"));
    root->addElement(std::move(imgDir));

    auto docsDir = std::make_unique<Directory>("docs");
    docsDir->addElement(std::make_unique<File>("manual.pdf"));
    root->addElement(std::move(docsDir));

    // Wypisywanie struktury
    root->print(std::cout);

    // Przykład użycia dynamic_cast i typeid
    std::cout << "\nSearching for files:\n";
    findAndPrintFiles(root.get());

    // Przykład gdzie dynamic_cast jest konieczny (static_cast byłby błędem):
    FileSystemElement* elem = new Directory("test");

    // To działa, bo elem faktycznie wskazuje na Directory
    Directory* dirPtr = dynamic_cast<Directory*>(elem);
    assert(dirPtr != nullptr);

    // Uwaga! static_cast<Directory*>(elem) byłby niebezpieczny,
    // bo gdyby elem wskazywało na File, dostalibyśmy UB (undefined behavior).

    delete elem;

    return 0;
}
