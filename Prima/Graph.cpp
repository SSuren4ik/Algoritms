#include "Graph.h"

Graph::Graph()
{
    size = 0;
    arr.clear();
    node_count = 0;
}
void Graph::print() 
{
    Link* tmp;
    for (int i = 0; i < node_count; i++) {
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

void Graph::read(const string& file_path)
{
    ifstream file;
    file.open(file_path);
    arr.clear();
    size = 2 * size + 5;
    arr.resize(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = new List(i);
    }

    node_count = 0;
    string line;
    if (file.is_open()) {
        for (int i = 0; getline(file, line);i++) {
            cout << line << endl;
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
            //arr[i]->print();
            ++node_count;
        }
    }
}

void Graph::save(const string& file_path)
{
    ofstream file;
    Link* tmp;
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
                    file << '(' << tmp->src << ',' << "w = " << tmp->weight << ')' << ' ';
                }
                tmp = tmp->next;
            }
            file << endl;
        }
    }
    tmp = NULL;
}