#include "List.h"
#include "Iterator.h"
List::List() {
    head = new Link();
    head->next = head;
}
List::List(List& l)
{
    Link* tmp = l.head->next;
    while (l.head != l.head->next)
    {
        add(tmp->src, tmp->weight);
        tmp = tmp->next;
    }
}
List& List:: operator= (const List& l)
{
    this->clear();
    Link* tmp = l.head->next;
    while (tmp != l.head)
    {
        add(tmp->src, tmp->weight);
        tmp = tmp->next;
    }
    return *this;
}
void List::add(int _src, int _w)
{
    Link* t = head->next;
    Link* tmp = new Link(_src, _w);
    while (t->next != head) {
        if (t->next->weight > _w) {
            tmp->next = t->next;
            t->next = tmp;
            return;
        }
        t = t->next;
    }
    t->next = tmp;
    tmp->next = head;
}
void List::clear()
{
    Link* tmp = head->next;
    Link* tmp1 = tmp->next;
    while (tmp != head)
    {
        delete tmp;
        tmp = tmp1;
        tmp1 = tmp->next;
    }
}
void List::read(string& file_path) {
    ifstream file;
    file.open(file_path);
    string line;
    if (file.is_open()) {
        Iterator iter(head->next);
        for (int i = 0; getline(file, line);++i)
        {
            //cout << line << endl;
            string elem;
            stringstream line_stream(line);
            while (getline(line_stream, elem, ' '))
            {
                if (stoi(elem) != 0)
                {
                }
                //v.push_back(stoi(elem));
            }
           // AddEdge(Edge(v[0], v[1], v[2]));
        }
    }
}

void List::save(string& file_path) {
    //ofstream file;
    //file.open(file_path);
    //if (file.is_open()) {
    //    for (int i = 0; i <= node_count; i++) {
    //        file << i << " <——> ";
    //        for (Pair v : adjList[i]) {
    //            file << "(" << v.first << ", w = " << v.second << ") ";
    //        }
    //        file << std::endl;
    //    }
    //}
}
List::~List()
{
    clear();
}