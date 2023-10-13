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

    QueueNode(int val, QueueNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

class Queue
{
private:
    QueueNode *head, *tail;
    int counter;

public:
    Queue()
    {
        head = tail = nullptr;
        counter = 0;
    }

    Queue(int val)
    {
        QueueNode *node = new QueueNode(val);
        head = tail = node;
        counter++;
    }

    void Enqueue(int val)
    {
        QueueNode *node = new QueueNode(val);
        counter++;

        if (isEmpty())
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        tail = node;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        QueueNode *current = head->next;
        head = current;

        if (counter == 1)
            tail = head;

        counter--;
    }

    bool Search(int target)
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
            cout << "Queue is empty --> ";
            return -1;
        }

        return head->val;
    }

    int getBack()
    {
        if (isEmpty())
        {
            cout << "Queue is empty --> ";
            return -1;
        }

        return tail->val;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int countNodes()
    {
        return counter;
    }

    void Print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

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
    queue->Enqueue(10);
    queue->Enqueue(20);
    queue->Enqueue(30);
    queue->Print();

    queue->Dequeue();
    queue->Print();

    queue->Dequeue();
    queue->Print();

    queue->Dequeue();
    queue->Print();

    queue->Enqueue(100);
    queue->Enqueue(200);
    queue->Print();

    cout << queue->getBack() << endl;
    cout << queue->getFront() << endl;
    cout << queue->countNodes() << endl;

    cout << queue->Search(200) << endl;
    cout << queue->Search(150) << endl;
}