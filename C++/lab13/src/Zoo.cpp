#include "Zoo.h"

int Zoo::whaleCount = 0;
int Zoo::birdCount = 0;

Zoo::Zoo() : animals(new std::vector<Animal*>()) {
    std::cout<<"Zoo constructor"<<std::endl;
}

Zoo::~Zoo(){
    delete animals;
    std::cout<<"Zoo destructor"<<std::endl;
}

void Zoo::print() const {
    for(auto an : *animals){
        std::cout<< an->me() << ": "<< an->name() << ", is mammal:" << an->isMammal()<<std::endl;
    }
}

void Zoo::addAnimal(Animal* new_animal){
    try {
        if (std::find(animals->begin(), animals->end(), new_animal) != animals->end()) {
            std::string addressStr = std::to_string(reinterpret_cast<uintptr_t>(new_animal));
            throw std::runtime_error("!!! There is already the animal of the same address (" + addressStr + ") in the zoo !!!");
        } 

        for (auto& existingAnimal : *animals) {
            if (existingAnimal->name() == new_animal->name()) {
                throw std::runtime_error("Animal with the same name " + new_animal->name() + " already exists!");
            }
        }

        if (dynamic_cast<Birds*>(new_animal)) {
            // int birdCount = 0;
            // for (auto& existingAnimal : *animals) {
            //     if (dynamic_cast<Birds*>(existingAnimal)) {
            //         ++birdCount;
            //     }
            // }
            this->birdCount++;
            if (birdCount > 5) {
                throw std::runtime_error("Zoo already has 5 birds, cannot add more!");
            }
        }

        if (dynamic_cast<Whales*>(new_animal)) {
            // int whaleCount = 0;
            // for (auto& existingAnimal : *animals) {
            //     if (dynamic_cast<Whales*>(existingAnimal)) {
            //         ++whaleCount;
            //     }
            // }
            this->whaleCount++;
            if (whaleCount > 2) {
                throw std::runtime_error("Zoo already has 2 whales, cannot add more!");
            }
        }

    animals->push_back(new_animal);
    std::cout << "Animal " << new_animal->name() << " added to zoo.\n";

    }catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
}