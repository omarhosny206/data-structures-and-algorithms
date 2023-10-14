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

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        QueueNode *nextNode = head->next;
        head = nextNode;
        size--;

        if (size == 0)
            tail = head = nullptr;
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
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return head->val;
    }

    int getBack()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

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
    Queue *queue = new Queue();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->print();

    queue->dequeue();
    queue->print();

    queue->dequeue();
    queue->print();

    queue->dequeue();
    queue->print();

    queue->enqueue(100);
    queue->enqueue(200);
    queue->print();

    cout << queue->getBack() << endl;
    cout << queue->getFront() << endl;
    cout << queue->getSize() << endl;

    cout << queue->search(200) << endl;
    cout << queue->search(150) << endl;
}