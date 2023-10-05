#include "Graph.h"

Graph::Graph() : size(0)
{
    adjList.clear();
    node_count = 0;
}

Graph::Graph(const std::vector<Edge>& edges) : size(0), node_count(0) 
{
    adjList.clear();
    node_count = 0;
    for (auto& edge : edges)
        AddEdge(edge);
}

void Graph::print() 
{
    for (int i = 0; i <= node_count; i++) {
        cout << i << " <——> ";
        for (Pair v : adjList[i]) {
            cout << "(" << v.first << ", w = " << v.second << ") ";
        }
        cout << endl;
    }
}

void Graph::AddEdge(const Edge& edge)
{
    int max_src = max(edge.start_ver, edge.start_ver);
    node_count = max(node_count, max_src);
    if (max_src > size|| size==0) {
        adjList.resize(size + 5);
        size += 5;
    }
    adjList[edge.start_ver].emplace_back(edge.end_ver, edge.weight);
}

vector<vector<Pair>> Graph::getList() const {
    return adjList;
}

int Graph::get_node_count() const {
    return node_count + 1;
}

void Graph::read(const std::string& file_path) {
    ifstream file;
    file.open(file_path);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            //cout << line << endl;
            vector<int> v;
            string elem;
            stringstream line_stream(line);
            while (getline(line_stream, elem, ' ')) {
                v.push_back(stoi(elem));
            }
            AddEdge(Edge(v[0], v[1], v[2]));
        }
    }
}

void Graph::save(const std::string& file_path) {
    ofstream file;
    file.open(file_path);
    if (file.is_open()) {
        for (int i = 0; i <= node_count; i++) {
            file << i << " <——> ";
            for (Pair v : adjList[i]) {
                file << "(" << v.first << ", w = " << v.second << ") ";
            }
            file << std::endl;
        }
    }
}