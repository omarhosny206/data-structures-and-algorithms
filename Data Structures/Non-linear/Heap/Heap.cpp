#include <bits/stdc++.h>
using namespace std;

class Comparator
{
public:
    virtual bool Compare(int first, int second) = 0;
};

class MaxComparator : public Comparator
{
    bool Compare(int first, int second)
    {
        return first > second;
    }
};

class MinComparator : public Comparator
{
    bool Compare(int first, int second)
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
            Insert(num);
    }

    void Insert(int &num)
    {
        heap.push_back(num);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void Delete()
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

    int Top()
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

        int parentIndex = Parent(index);
        if (comparator->Compare(heap[index], heap[parentIndex]))
        {
            Swap(index, parentIndex);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        if (isValidLeaf(index))
            return;

        int largestNumberIndex = index;
        int leftIndex = Left(index);
        int rightIndex = Right(index);

        if (comparator->Compare(heap[leftIndex], heap[largestNumberIndex]))
            largestNumberIndex = leftIndex;

        if (comparator->Compare(heap[rightIndex], heap[largestNumberIndex]))
            largestNumberIndex = rightIndex;

        if (largestNumberIndex != index)
        {
            Swap(index, largestNumberIndex);
            heapifyDown(largestNumberIndex);
        }
    }

    void Sort()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        while (!isEmpty())
        {
            cout << Top() << " ";
            Delete();
        }
    }

    int Parent(int index)
    {
        return (index - 1) / 2;
    }

    int Left(int index)
    {
        return (index * 2) + 1;
    }

    int Right(int &index)
    {
        return (index * 2) + 2;
    }

    bool isEmpty()
    {
        return heap.size() == 0;
    }

    bool isValidLeaf(int index)
    {
        return !isValidIndex(Left(index)) && !isValidIndex(Right(index));
    }

    bool isValidIndex(int index)
    {
        return index < heap.size();
    }

    void Swap(int i, int j)
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

    minHeap->Sort();
    cout << endl;

    maxHeap->Sort();
    cout << endl;
}