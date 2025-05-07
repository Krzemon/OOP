#include "Dir.h"
#include "File.h"
#include "Link.h"
#include <iostream>
#include <typeinfo>
#include <algorithm>

Dir::Dir(const std::string& name): FileSystemElement(name) {}

void Dir::add(std::unique_ptr<FileSystemElement> element) {
    elements.push_back(std::move(element));
}

void Dir::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Dir: " << name << "\n";
    for (auto& elem : elements) {
        elem->print(os, indent + 2);
    }
}

const std::string& Dir::getName() const { return name; }

std::vector<std::unique_ptr<FileSystemElement>>& Dir::getElements() {
    return elements;
}

// void Dir::rm(std::string name, bool removeTarget) {
//     for (auto iter = elements.begin(); iter != elements.end(); ) {
//         if ((*iter)->getName() == name) {
//             if (removeTarget) {
//                 iter = elements.erase(iter); // erase zwraca poprawiony iterator
//                 continue; // NIE wykonujemy ++iter po erase
//             } else {
//                 iter = elements.erase(iter); // usuwamy niezależnie od removeTarget
//                 continue;
//             }
//         }

//         // Jeśli to katalog, przeszukujemy rekurencyjnie
//         if (Dir* subdir = dynamic_cast<Dir*>(iter->get())) {
//             subdir->rm(name, removeTarget);
//         }

//         ++iter;
//     }
// }


void Dir::rm(std::string name, bool removeTarget) {
    for (auto iter = elements.begin(); iter != elements.end(); ) {
        if ((*iter)->getName() == name) {
            // Jeśli to link i removeTarget = true, usuwamy też obiekt, na który wskazuje
            if (removeTarget) {
                if (Link* link = dynamic_cast<Link*>(iter->get())) {
                    FileSystemElement* target = link->getTarget();

                    // Rekurencyjna funkcja do usuwania targetu ze wszystkich podkatalogów
                    auto removeTargetRecursively = [&](FileSystemElement* targetToRemove, Dir* currentDir, auto& self) -> void {
                        for (auto it = currentDir->elements.begin(); it != currentDir->elements.end(); ) {
                            if (it->get() == targetToRemove) {
                                it = currentDir->elements.erase(it);
                            } else {
                                if (Dir* sub = dynamic_cast<Dir*>(it->get())) {
                                    self(targetToRemove, sub, self); // rekurencja
                                }
                                ++it;
                            }
                        }
                    };

                    removeTargetRecursively(target, this, removeTargetRecursively);
                }
            }

            // Usuń sam element (link, plik, katalog)
            iter = elements.erase(iter);
        } else {
            // Rekurencja w podkatalogach
            if (Dir* subdir = dynamic_cast<Dir*>(iter->get())) {
                subdir->rm(name, removeTarget);
            }
            ++iter;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Dir& dir) {
    dir.print(os, 0);
    return os;
}