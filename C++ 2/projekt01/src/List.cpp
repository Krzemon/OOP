#include "List.h"

Node::Node(const Data &data) : _next(nullptr)
{
    data.clone(&_data);
}

Node::~Node()
{
    delete _data;
}

List::List() : _head(nullptr)
{
}

List::List(const List &list) : _head(nullptr)
{
    for (Node *n = list._head; n; n = n->_next)
        insert(*(n->_data));
}

List &List::operator=(const List &list)
{
    if (this == &list)
        return *this;

    this->~List();
    copyFromList(list);

    return *this;
}

List::~List()
{
    Node *tmp;
    for (Node *n = _head; n; n = tmp)
    {
        tmp = n->_next;
        delete n;
    }

    _head = nullptr;
}

List &List::insert(const Data &data, int idx)
{
    if (!_head)
    {
        _head = new Node(data);
        return *this;
    }

    switch (idx)
    {
    case -1:
        insertHead(data);
        break;
    case -2:
        insertTail(data);
        break;
    default:
        insertAfter(data, idx);
        break;
    }

    return *this;
}

void List::print(std::ostream &os) const
{
    os << '[';
    for (Node *n = _head; n; n = n->_next)
    {
        n->_data->print(os);
        if (n->_next)
            os << ", ";
    }
    os << ']' << std::endl;
}

void List::insertHead(const Data &data)
{
    Node *new_head = new Node(data);

    new_head->_next = _head;

    _head = new_head;
}

void List::insertAfter(const Data &data, int idx)
{
    Node *prev_node = _head;

    while (prev_node->_next && idx--)
        prev_node = prev_node->_next;

    Node *new_node = new Node(data);

    new_node->_next = prev_node->_next;
    prev_node->_next = new_node;
}

void List::insertTail(const Data &data)
{
    Node *tail = _head;

    while (tail->_next)
        tail = tail->_next;

    Node *new_tail = new Node(data);

    tail->_next = new_tail;
}

void List::copyFromList(const List &list)
{
    for (Node *n = list._head; n; n = n->_next)
        insert(*(n->_data));
}
