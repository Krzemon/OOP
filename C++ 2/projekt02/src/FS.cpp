#include "FS.h"

#include "Dir.h"
#include "File.h"

FS::FS()
{
}

FS::~FS()
{
    for (FSElement *elem : _elems)
    {
        delete elem;
    }

    _elems.clear();
}

std::vector<FSElement *> FS::getFSElements(Type type, int depth)
{
    std::vector<FSElement *> founded_elems{};

    if (depth > 0)
    {
        auto extend = [](std::vector<FSElement *> &dst, const std::vector<FSElement *> &src)
        {
            dst.insert(dst.end(), src.cbegin(), src.cend());
        };

        for (FSElement *elem : _elems)
        {
            switch (type)
            {
            case Type::All:
                founded_elems.push_back(elem);
                break;

            case Type::File:
                if (dynamic_cast<File *>(elem))
                {
                    founded_elems.push_back(elem);
                }
                break;

            case Type::Dir:
                if (dynamic_cast<Dir *>(elem))
                {
                    founded_elems.push_back(elem);
                }

                break;

            default:
                break;
            }

            FS *temp_fs = dynamic_cast<FS *>(elem);

            if (temp_fs)
            {
                extend(founded_elems, temp_fs->getFSElements(type, depth - 1));
            }
        }
    }

    return founded_elems;
}

void FS::operator+=(FSElement *elem)
{
    _elems.push_back(elem);
}

FS *FS::add(FSElement *elem)
{
    _elems.push_back(elem);
    return this;
}

FSElement *FS::get(const std::string &name)
{
    Dir *temp_dir = nullptr;
    FSElement *res = nullptr;

    for (FSElement *elem : _elems)
    {

        if (elem->getName() == name)
        {
            return elem;
        }

        temp_dir = dynamic_cast<Dir *>(elem);

        if (temp_dir)
        {
            res = temp_dir->get(name);

            if (res)
            {
                return res;
            }
        }
    }
    return nullptr;
}