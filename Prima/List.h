#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Link.h"
using namespace std;

class List {
private:
    Link* start;
    Link* end;
public:
    List();
    List(int k);
    List(List& l);
    List& operator= (const List& l);
    void add(int _src, int _w);
    void last_add(int _src, int _w);
    void print();
    Link* gethead();
    bool IsEmpty();
    void del_first();
    void clear();
    ~List();
};
