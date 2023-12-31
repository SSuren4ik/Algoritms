#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "List.h"
const int n = 4001;

class Graph 
{
    vector<List*> arr;
    size_t size;
    int node_count;
public:
    Graph();
    Graph(int s);
    void print();
    void read(const string& file_path);
    void save(const string& file_path);
    int get_node_count() const;
    vector<List*> get_List();
    void add_edge(int src, int end, int w);   
    ~Graph();
};