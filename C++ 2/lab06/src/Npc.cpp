#include "Npc.h"

void NPC::interact() const {
    std::cout << "NPC talks!" << std::endl;
}

void NPC::printComplexity() const {
    std::cout << "NPC complexity: " << _complexity << std::endl;
}