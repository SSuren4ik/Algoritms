#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;


class DHeap
{
private:
    vector<Pair> heap; // first -  end, second - weight 
    int d; // степень кучи
    int n;
public:
    DHeap();
    void insert(Pair key);
    int first_child(int i);
    int last_child(int i);
    int father(int i);
    void removeMin();
    Pair getMin();
    void heapifyUp(int index);
    void heapifyDown(int index);
    int getMinChildIndex(int index);
    void printHeap();
    void printHeapSrc();
    ~DHeap();
};