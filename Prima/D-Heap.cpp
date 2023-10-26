#include "D-Heap.h"

DHeap::DHeap() {
    d =10;
    n = heap.size() - 1;
}

void DHeap::insert(Pair value)
{
    heap.push_back(value);
    int currentIndex = heap.size() - 1;
    while (currentIndex > 0)
    {
        if (heap[father(currentIndex)].second > heap[currentIndex].second)
        {
            swap(heap[currentIndex], heap[father(currentIndex)]);
        }
        else if (heap[father(currentIndex)].second == heap[currentIndex].second)
        {
            if(heap[father(currentIndex)].first > heap[currentIndex].first)
            {
                swap(heap[currentIndex], heap[father(currentIndex)]);
            }
        }
        currentIndex = father(currentIndex);
    }
    n = heap.size() - 1;
}
int DHeap::first_child(int i)
{
    int k = i*d + 1;
    if (k > n)
        return -1;
    return k;
}

int DHeap::last_child(int i)
{
    int k = first_child(i);
    if (k == -1)
        return -1;
    return min(k + d - 1, n);
}

int DHeap::father(int i)
{
    return (i - 1) / d;
}

int DHeap::getMinChildIndex(int index)
{
    int fch = first_child(index);
    int lch = last_child(index);
    if (fch < 0 || lch < 0)
        return -1;
    int maxChild = -1;
    int maxValue = INT_MAX;
    for (int i = fch; i <= lch; i++)
    {
        if (heap[i].second < maxValue) {
            maxValue = heap[i].second;
            maxChild = i;
        }
    }

    return maxChild;
}

void DHeap::removeMin() 
{
    if (heap.empty()) 
    {
        throw exception("Куча пуста");
    }
    Pair p = heap[0];
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    n = heap.size() - 1;
    heapifyDown(0);
}
Pair DHeap::getMin()
{
    if (heap.empty())
    {
        return Pair(-1,-1);
    }
    return heap[0];
}

void DHeap::heapifyDown(int index) 
{
    int maxChild = getMinChildIndex(index);

    if (maxChild != -1 && heap[index].second > heap[maxChild].second)
    {
        swap(heap[index], heap[maxChild]);
        heapifyDown(maxChild);
    }
    else if (maxChild != -1 && heap[index].second == heap[maxChild].second)
    {
        if (heap[index].first > heap[maxChild].first)
        {
            swap(heap[index], heap[maxChild]);
            heapifyDown(maxChild);
        }
    }
}

void DHeap::printHeap() 
{
    for (int i=0; i < heap.size();++i)
    {
        cout << heap[i].second << " ";
    }
    cout << endl;
}
void DHeap::printHeapSrc()
{
    for (int i = 0; i < heap.size(); ++i)
    {
        cout << heap[i].first << " ";
    }
    cout << endl;
}

DHeap::~DHeap()
{
    heap.clear();
}