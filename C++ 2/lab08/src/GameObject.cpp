#include "GameObject.h"

std::vector<GameObject*>& GameObject::ActiveGameObjects() {
    static std::vector<GameObject*> activeObjects;
    return activeObjects;
}

GameObject* GameObject::addGameObject(GameObject* obj) {
    ActiveGameObjects().push_back(obj);
    return obj;
}

void GameObject::destroyGameObject(GameObject* obj) {
    auto& objects = ActiveGameObjects();
    auto it = std::find(objects.begin(), objects.end(), obj);
    if (it != objects.end()) {
        delete *it;
        objects.erase(it);
    }
}

void GameObject::destroyGameObjects() {
    auto& objects = ActiveGameObjects();
    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();
}
