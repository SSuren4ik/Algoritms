#include "Graph.h"

Graph::Graph()
{
    size = 0;
    arr.clear();
    node_count = 0;
}
Graph::Graph(int s = 0)
{
    size = s;
    node_count = s;
    for (int i = 0; i < size; ++i)
    {
        arr.push_back(new List(i));
    }
}

int Graph::get_node_count() const
{
    return node_count;
}

void Graph::print() 
{
    Link* tmp;
    for (int i = 0; i < node_count; i++) 
    {
        if (!arr[i]->IsEmpty())
        {
            cout << i << " <——> ";
            tmp = arr[i]->gethead()->next;
            while (tmp!=nullptr) 
            {
                cout << '(' << tmp->src << ", w = " << tmp->weight << ") ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
}

void Graph::read(const string& file_path)
{
    ifstream file;
    file.open(file_path);
    arr.clear();
    size = 10;
    arr.reserve(size);
    for (int i = 0; i < size; ++i)
    {
        arr.push_back(new List(i));
    }

    node_count = 0;
    string line;
    if (file.is_open()) {
        for (int i = 0; getline(file, line);i++)
        {
            if (size <= i)
            {
                int nsize = 2 * size + 5;
                arr.reserve(nsize);
                for (int m = size; m < nsize; ++m)
                {
                    arr.push_back(new List(m));
                }
                size = nsize;
            }
            string elem;
            stringstream line_stream(line);
            for (int k = 0; getline(line_stream, elem, ' ');k++)
            {
                int ch = stoi(elem);
                if (ch != 0)
                {
                    arr[i]->last_add(k, ch);
                }
            }
            //cout << i << endl;
            //arr[i]->print();
            ++node_count;
        }
    }
}

void Graph::save(const string& file_path)
{
    ofstream file;
    Link* tmp;
    int sum = 0;
    file.open(file_path);
    if (file.is_open())
    {
        for (int i = 0; i < node_count; ++i)
        {
            tmp = arr[i]->gethead();
            file << tmp->src << " <——> ";
            while (tmp!=nullptr)
            {
                if(tmp->weight!=0)
                {
                    sum += tmp->weight;
                    file << '(' << tmp->src << ',' << "w = " << tmp->weight << ')' << ' ';
                }
                tmp = tmp->next;
            }
            file << endl;
        }
        file << "Âåñ ãðàôà = " << sum << endl;
    }
    tmp = NULL;
}

vector<List*> Graph::get_List()
{
    return arr;
}

void Graph::add_edge(int src, int end, int _w)
{
    arr[src]->last_add(end, _w);
}

Graph::~Graph()
{
    for (int i = 0; i < arr.size(); ++i)
        delete arr[i];
    arr.clear();
}