#include <bits/stdc++.h>
using namespace std;

class Comparator
{
public:
    virtual bool compare(int first, int second) = 0;
};

class MaxComparator : public Comparator
{
    bool compare(int first, int second)
    {
        return first > second;
    }
};

class MinComparator : public Comparator
{
    bool compare(int first, int second)
    {
        return first < second;
    }
};

class Heap
{
private:
    vector<int> heap;
    Comparator *comparator;

public:
    Heap(vector<int> &data, Comparator *comparator)
    {
        this->comparator = comparator;

        for (int &num : data)
            push(num);
    }

    void push(int &num)
    {
        heap.push_back(num);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        return heap[0];
    }

    void heapifyUp(int index)
    {
        if (index == 0)
            return;

        int parentIndex = parent(index);
        if (comparator->compare(heap[index], heap[parentIndex]))
        {
            swap(index, parentIndex);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        if (isValidLeaf(index))
            return;

        int largestNumberIndex = index;
        int leftIndex = left(index);
        int rightIndex = right(index);

        if (comparator->compare(heap[leftIndex], heap[largestNumberIndex]))
            largestNumberIndex = leftIndex;

        if (comparator->compare(heap[rightIndex], heap[largestNumberIndex]))
            largestNumberIndex = rightIndex;

        if (largestNumberIndex != index)
        {
            swap(index, largestNumberIndex);
            heapifyDown(largestNumberIndex);
        }
    }

    void sort()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        while (!isEmpty())
        {
            cout << top() << " ";
            pop();
        }
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int left(int index)
    {
        return (index * 2) + 1;
    }

    int right(int &index)
    {
        return (index * 2) + 2;
    }

    bool isEmpty()
    {
        return heap.size() == 0;
    }

    bool isValidLeaf(int index)
    {
        return !isValidIndex(left(index)) && !isValidIndex(right(index));
    }

    bool isValidIndex(int index)
    {
        return index < heap.size();
    }

    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
};

int main()
{
    vector<int> data = {15, 7, 6, 2, 9, 33, 4};

    Heap *minHeap = new Heap(data, new MinComparator());
    Heap *maxHeap = new Heap(data, new MaxComparator());

    minHeap->sort();
    cout << endl;

    maxHeap->sort();
    cout << endl;
}