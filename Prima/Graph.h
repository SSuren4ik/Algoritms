#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#ifndef GRAPH_H
#define GRAPH_H


using namespace std;

typedef pair<int, int> Pair;

struct Edge {
    int start_ver, end_ver, weight;
    Edge(int sv, int ev, int w) :start_ver(sv), end_ver(ev), weight(w){}
    bool operator<(const Edge& e) const 
    {
        return (weight < e.weight);
    }
};

class Graph 
{
    vector<vector<Pair>> adjList;
    size_t size;
    int node_count;
public:
    Graph();
    Graph(vector<Edge> const& edges);
    void AddEdge(Edge const& edge);
    void print();
    void read(const string& file_path);
    void save(const string& file_path);
    vector<vector<Pair>> getList() const;
    int get_node_count() const;

};

#endif 