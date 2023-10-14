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
    Heap(vector<int> &values, Comparator *comparator)
    {
        this->comparator = comparator;

        for (int &val : values)
            insert(val);
    }

    void insert(int &val)
    {
        heap.push_back(val);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }

    int getTop()
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
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

        int largestValueIndex = index;
        int leftIndex = left(index);
        int rightIndex = right(index);

        if (comparator->compare(heap[leftIndex], heap[largestValueIndex]))
            largestValueIndex = leftIndex;

        if (comparator->compare(heap[rightIndex], heap[largestValueIndex]))
            largestValueIndex = rightIndex;

        if (largestValueIndex != index)
        {
            swap(index, largestValueIndex);
            heapifyDown(largestValueIndex);
        }
    }

    void sort()
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
            return;
        }

        while (!isEmpty())
        {
            cout << getTop() << " ";
            remove();
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