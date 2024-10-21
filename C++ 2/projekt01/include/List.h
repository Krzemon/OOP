#ifndef LIST_H
#define LIST_H

#include "Data.h"

class List;

class Node
{
    friend class List;

public:
    Node(const Data& data);
    ~Node();

private:
    Data *_data;
    Node *_next;
};

class List
{
public:
    List();
    List(const List &list);
    List &operator=(const List &list);

    ~List();

    enum Index
    {
        Begin = -1,
        End = -2,
    };

    List &insert(const Data &data, int idx = Index::End);
    void print(std::ostream &os = std::cout) const;

private:
    Node *_head;

    void insertHead(const Data &data);
    void insertAfter(const Data &data, int idx);
    void insertTail(const Data &data);

    void copyFromList(const List& list);
};

#endif