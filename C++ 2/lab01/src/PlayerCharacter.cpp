#include "PlayerCharacter.h"

#include <iostream>

void GameObject::info(){
    std::cout<<"Rendering GameObject"<<std::endl;
}

GameObject::~GameObject(){};

void Renderable::info(){
    std::cout<<"Drawing Renderable"<<std::endl;
}

Renderable::~Renderable(){};

void PlayerCharacter::attack(){
    std::cout<<"PlayerCharacter attacking!"<<std::endl;
}

void gutils::handleGameObject(GameObject* gameObject){
    gameObject->info();
    dynamic_cast<PlayerCharacter*>(gameObject)->attack();
}

void gutils::handleRenderable(Renderable* renderable){
    renderable->info();
    dynamic_cast<PlayerCharacter*>(renderable)->attack();
}
