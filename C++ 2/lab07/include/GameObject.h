#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

class GameObject {
public:
    virtual void action() = 0;
    virtual ~GameObject() {} // Wirtualny destruktor
    static std::vector<GameObject*>& ActiveGameObjects();
    static GameObject* addGameObject(GameObject* obj);
    static void destroyGameObject(GameObject* obj);
    static void destroyGameObjects();
};

// Deklaracja funkcji performRuntimeTypeChecking
void performRuntimeTypeChecking(GameObject* obj);

#endif // GAMEOBJECT_H