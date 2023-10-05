#include <iostream>
#include <vector>

using namespace std;

class DHeap {
private:
    vector<int> heap;
    int d; // степень кучи
    int n;
public:
    DHeap(int _d) {
        d = _d;
        n = heap.size() - 1;
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }
    int first_child(int i)
    {
        int k = (i - 1) * d + 2;
        if (k > n)
            return 0;
        return k;
    }

    int last_child(int i)
    {
        int k = first_child(i);
        if (k == 0)
            return 0;
        return min(k + d - 1, n);
    }

    int father(int i)
    {
        return (i - 2) / d + 1;
    }

    int minchild(int i)
    {
        int minch;
        int kf = first_child(i);
        if (kf == 0)
            return i;
        int kl = last_child(i);
        int min_key = heap[kf];
        minch = kf;
        for (int j = kf + 1; j < kl;)
        {
            if (heap[j] < min_key)
            {
                min_key = heap[j];
                minch = j;
            }
        }
        return minch;
    }

    void removeMax() {
        if (heap.empty()) {
            cout << "Куча пуста" << endl;
            return;
        }
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / d;

        if (parent >= 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int maxChild = getMaxChildIndex(index);

        if (maxChild != -1 && heap[index] < heap[maxChild]) {
            swap(heap[index], heap[maxChild]);
            heapifyDown(maxChild);
        }
    }

    int getMaxChildIndex(int index) {
        int firstChild = d * index + 1;
        int lastChild = d * index + d;
        int maxChild = -1;
        int maxValue = INT_MIN;

        for (int i = firstChild; i <= lastChild && i < heap.size(); i++) {
            if (heap[i] > maxValue) {
                maxValue = heap[i];
                maxChild = i;
            }
        }

        return maxChild;
    }

    void printHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};