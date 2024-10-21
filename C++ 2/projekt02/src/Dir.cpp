#include "Dir.h"

Dir::Dir(const std::string &name) : FS(), FSElement(name)
{
}

void Dir::print(size_t spaces, std::ostream &os) const
{

    auto print_spaces = [spaces](std::ostream &os)
    {
        for (int i = 0; i < spaces; ++i)
            os << " ";
    };

    print_spaces(os);

    os << _name << " (DIR)" << std::endl;

    for (FSElement *elem : _elems)
        elem->print(spaces + 2, os);
}

Dir *Dir::findDir(const std::string &name)
{
    return dynamic_cast<Dir *>(this->get(name));
}

void Dir::listDirs(int depth, std::ostream &os)
{
    os << _name << " ";
    for (FSElement *elem : getFSElements(Type::Dir, depth))
        os << elem->getName() << " ";
    os << std::endl;
}
