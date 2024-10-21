#ifndef FS_h
#define FS_h

#include "FSElement.h"

class FS
{
public:
    FS();

    virtual ~FS();

    std::vector<FSElement *> getFSElements(Type type = Type::All, int depth = 1);

    // dodanie obiektu
    virtual void operator+=(FSElement *elem);

    // dodanie obiektu
    virtual FS *add(FSElement *elem);

    // szukanie obiektu - rekursywne
    virtual FSElement *get(const std::string &name);

protected:
    std::vector<FSElement *> _elems;
};

#endif