#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

class GameObject {
public:
    static std::vector<GameObject*>& ActiveGameObjects();

    static GameObject* addGameObject(GameObject* obj);
    static void destroyGameObject(GameObject* obj);
    static void destroyGameObjects();

    virtual ~GameObject() {}
    virtual void action() = 0;
    virtual std::string Name() const = 0;
protected:
    GameObject() {}
};

#endif // GAMEOBJECT_H
