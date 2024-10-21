#include "Dir.h"
#include "File.h"
#include <algorithm>

Dir::~Dir() {
    for (auto elem : elements) {
        delete elem;
    }
}

void Dir::add(FSElement* elem) {
    elements.push_back(elem);
}

Dir* Dir::findDir(const std::string& name) {
    for (auto elem : elements) {
        if (auto dir = dynamic_cast<Dir*>(elem)) {
            if (dir->getName() == name) {
                return dir;
            }
            auto found = dir->findDir(name);
            if (found) {
                return found;
            }
        }
    }
    return nullptr;
}

std::vector<FSElement*> Dir::getDirs() const {
    std::vector<FSElement*> dirs;
    for (auto elem : elements) {
        if (auto dir = dynamic_cast<Dir*>(elem)) {
            dirs.push_back(dir);
        }
    }
    return dirs;
}

std::vector<FSElement*> Dir::getFSElements(Type type, int depth) {
    std::vector<FSElement*> fsElements;
    if (depth < 0) return fsElements;

    for (auto elem : elements) {
        if ((type == Type::Dir && dynamic_cast<Dir*>(elem)) || (type == Type::File && dynamic_cast<File*>(elem))) {
            fsElements.push_back(elem);
        }
        if (auto dir = dynamic_cast<Dir*>(elem)) {
            auto subElements = dir->getFSElements(type, depth - 1);
            fsElements.insert(fsElements.end(), subElements.begin(), subElements.end());
        }
    }
    return fsElements;
}

void Dir::listDirs(int depth) const {
    listDirsRecursive(this, depth, 0);
}

void Dir::listDirsRecursive(const Dir* dir, int depth, int currentDepth) const {
    if (currentDepth > depth) {
        return;
    }

    std::cout << dir->getName() << " "; // Wypisanie nazwy katalogu z separatorem spacji
    if (currentDepth == depth) {
        return;
    }

    for (auto subDir : dir->getDirs()) {
        listDirsRecursive(dynamic_cast<const Dir*>(subDir), depth, currentDepth + 1);
    }

    if (currentDepth == 0) { // Jeśli jesteśmy na głównym poziomie, przejdź do nowej linii
        std::cout << std::endl;
    }
}

void Dir::print(std::ostream& os, int depth) const {
    os << std::string(depth, ' ') << getName() << " (DIR)" << std::endl;
    for (const auto& elem : elements) {
        elem->print(os, depth + 1);
    }
}
