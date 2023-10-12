#include "List.h"
List::List() {
    start = new Link();
    end = start;
}

List::List(int k=0)
{
    start = new Link(k);
    end = start;
}

List::List(List& l)
{
    start = new Link(0,0, end);
    end = start;
    Link* tmp = l.start->next;
    while (tmp != nullptr)
    {
        last_add(tmp->src,tmp->weight);
        tmp = tmp->next;
    }
}

List& List:: operator= (const List& l)
{
    this->clear();
    Link* tmp = l.start->next;
    while (tmp != l.start)
    {
        add(tmp->src, tmp->weight);
        tmp = tmp->next;
    }
    return *this;
}

void List::del_first()
{
    if (IsEmpty())
        throw exception();
    Link* p = start;
    start = p->next;
    delete p;
    if (IsEmpty())
        end = nullptr;
}

void List::add(int _src, int _w)
{
    Link* t = start;
    Link* tmp = new Link(_src, _w);
    while (t->next!=nullptr) {
        if (t->next->weight > _w) {
            tmp->next = t->next;
            t->next = tmp;
            return;
        }
        t = t->next;
    }
    t->next = tmp;
    end = t->next;
}

Link* List::gethead()
{
    return start;
}

void List::print()
{
    Link* tmp = start->next;
    while (tmp != nullptr)
    {
        cout << tmp->src << " w = " << tmp->weight << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void List::last_add(int _src, int _w)
{
    end->next = new Link(_src, _w);
    end = end->next;
}

bool List::IsEmpty()
{
    return start == end;
}

void List::clear()
{
    while (!IsEmpty())
        del_first();
}

List::~List()
{
    clear();
}