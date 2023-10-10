#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#ifndef GRAPH_H
#define GRAPH_H
#include "List.h"
#include "Iterator.h"

using namespace std;

class Graph 
{
    vector<List*> arr;
    size_t size;
    int node_count;
public:
    Graph();
    void print();
    void read(const string& file_path);
    void save(const string& file_path);
};

#endif 