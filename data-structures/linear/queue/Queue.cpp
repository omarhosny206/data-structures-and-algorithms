#include <bits/stdc++.h>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode *next;

    QueueNode()
    {
        next = nullptr;
    }

    QueueNode(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class Queue
{
private:
    QueueNode *head;
    QueueNode *tail;
    int size;

public:
    Queue()
    {
        head = tail = nullptr;
        size = 0;
    }

    Queue(int val)
    {
        QueueNode *newNode = new QueueNode(val);
        head = tail = newNode;
    }

    Queue(vector<int> &values)
    {
        for (int &val : values)
            enqueue(val);
    }

    void enqueue(int val)
    {
        QueueNode *newNode = new QueueNode(val);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
            throw runtime_error("Cannot dequeue, the queue is empty.");

        QueueNode *temp = head;
        QueueNode *nextNode = head->next;
        head = nextNode;
        size--;

        if (size == 0)
            tail = head = nullptr;

        return temp->val;
    }

    bool search(int target)
    {
        QueueNode *current = head;

        while (current != nullptr)
        {
            if (current->val == target)
                return true;

            current = current->next;
        }

        return false;
    }

    int getFront()
    {
        if (isEmpty())
            throw runtime_error("Cannot get front, the queue is empty.");

        return head->val;
    }

    int getBack()
    {
        if (isEmpty())
            throw runtime_error("Cannot get back, the queue is empty.");

        return tail->val;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        QueueNode *current = head;

        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    vector<int> values = {10, 20, 30};
    Queue *queue = new Queue(values);
    queue->enqueue(40);

    cout << "Print: " << endl;
    queue->print();

    cout << "Dequeue: " << queue->dequeue() << endl;
    cout << "Dequeue: " << queue->dequeue() << endl;

    cout << "Print: " << endl;
    queue->print();

    cout << "Front: " << queue->getFront() << endl;
    cout << "Back: " << queue->getBack() << endl;
    cout << "Size: " << queue->getSize() << endl;

    cout << "Search for 30: " << queue->search(30) << endl;
    cout << "Search for 50: " << queue->search(50) << endl;
}