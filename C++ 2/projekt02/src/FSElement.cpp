#include "FSElement.h"

FSElement::FSElement(const std::string &name) : _name(name)
{
}

std::string FSElement::getName() const
{
    return _name;
}

std::ostream &operator<<(std::ostream &os, const FSElement &elem)
{
    elem.print(0, os);
    return os;
}
