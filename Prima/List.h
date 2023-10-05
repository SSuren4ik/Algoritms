#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Link.h"
using namespace std;

class List {
private:
    Link* head;
public:
    List();
    List(List& l);
    List& operator= (const List& l);
    void add(int _src, int _w);
    void read(string& file_path);
    void save(string& file_path);
    void clear();
    ~List();
};



//bool find(int x) {
//    Link* t = head->next;
//    while (t != head) {
//        if (t->val == x)
//            return true;
//        t = t->next;
//    }
//    return false;
//}
    //friend ostream& operator <<(ostream& out, List& obj)
    //{
    //    Link* t = obj.head->next;
    //    while (t != obj.head) {
    //        out << t->val << ' ';
    //        t = t->next;
    //    }
    //    return out;
    //}
    //friend istream& operator >> (istream& in, List& obj)
    //{
    //    obj.clear();
    //    string s;
    //    string sep = "$";
    //    while (true) {
    //        in >> s;
    //        if (s == sep)
    //            break;
    //        obj.add(stoi(s));
    //    }
    //    return in;
    //}