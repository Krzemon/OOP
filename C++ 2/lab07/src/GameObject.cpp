#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

// Implementacja statycznej funkcji ActiveGameObjects
std::vector<GameObject*>& GameObject::ActiveGameObjects() {
    static std::vector<GameObject*> activeGameObjects;
    return activeGameObjects;
}

// Implementacja statycznej funkcji addGameObject
GameObject* GameObject::addGameObject(GameObject* obj) {
    ActiveGameObjects().push_back(obj);
    return obj;
}

// Implementacja statycznej funkcji destroyGameObject
void GameObject::destroyGameObject(GameObject* obj) {
    auto& activeGameObjects = ActiveGameObjects();
    for (auto it = activeGameObjects.begin(); it != activeGameObjects.end(); ++it) {
        if (*it == obj) {
            activeGameObjects.erase(it);
            break;
        }
    }
    delete obj;
}

// Implementacja statycznej funkcji destroyGameObjects
void GameObject::destroyGameObjects() {
    auto& activeGameObjects = ActiveGameObjects();
    for (auto obj : activeGameObjects) {
        delete obj;
    }
    activeGameObjects.clear();
}

// Implementacja funkcji performRuntimeTypeChecking
void performRuntimeTypeChecking(GameObject* obj) {
    if (dynamic_cast<Player*>(obj)) {
        std::cout << "Player object is renderable collidable" << std::endl;
    } else if (dynamic_cast<Enemy*>(obj)) {
        std::cout << "Enemy object is renderable collidable updatable" << std::endl;
    }
}