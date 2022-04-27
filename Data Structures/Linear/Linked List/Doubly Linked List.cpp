#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *previous;

    ListNode()
    {
        this->next = nullptr;
        this->previous = nullptr;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->previous = nullptr;
    }

    ListNode(int val, ListNode *next, ListNode *previous)
    {
        this->val = val;
        this->next = next;
        this->previous = previous;
    }
};

class LinkedList
{
public:
    ListNode *head, *tail;
    int numNodes;

    LinkedList()
    {
        this->head = this->tail = nullptr;
        this->numNodes = 0;
    }

    LinkedList(vector<int> &data)
    {
        for (int &val : data)
            Add(val);
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void Add(int val)
    {
        ListNode *node = new ListNode(val);

        if (isEmpty())
            head = tail = node;

        else
        {
            tail->next = node;
            node->previous = tail;
            tail = node;
        }

        numNodes++;
    }

    void addAtFirst(int val)
    {
        ListNode *node = new ListNode(val);

        if (isEmpty())
            head = tail = node;

        else
        {
            head->previous = node;
            node->next = head;
            head = node;
        }

        numNodes++;
    }

    void addAtPosition(int val, int position)
    {
        if (position < 0 || position > numNodes)
        {
            cout << "Out Of Boundary!" << endl;
            return;
        }

        if (position == 0)
        {
            addAtFirst(val);
            return;
        }

        else if (position == numNodes)
        {
            Add(val);
            return;
        }

        ListNode *node = new ListNode(val);
        ListNode *current = head;

        while (--position)
            current = current->next;

        node->next = current->next;
        current->next->previous = node;
        current->next = node;
        node->previous = current;

        numNodes++;
    }

    void Delete()
    {
        if (isEmpty())
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        if (numNodes == 1)
            head = tail = nullptr;

        else
        {
            ListNode *current = head;

            while (current->next != tail)
                current = current->next;

            tail->previous = nullptr;
            current->next = nullptr;
            delete tail;
            tail = current;
        }

        numNodes--;
    }

    void deleteAtFirst()
    {
        if (isEmpty())
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        if (numNodes == 1)
            head = tail = nullptr;

        else
        {
            ListNode *current = head->next;
            current->previous = nullptr;
            delete head;
            head = current;
        }

        numNodes--;
    }

    void deleteAtPosition(int position)
    {
        if (isEmpty())
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        if (position < 0 || position >= numNodes)
        {
            cout << "Out Of Boundary!" << endl;
            return;
        }

        if (position == 0)
        {
            deleteAtFirst();
            return;
        }

        else if (position == numNodes - 1)
        {
            Delete();
            return;
        }

        ListNode *current = head;

        while (--position)
            current = current->next;

        ListNode *temp = current->next;

        current->next = temp->next;
        temp->next->previous = current;
        delete temp;

        numNodes--;
    }

    void deleteByValue(int val)
    {
        int position = Search(val);

        if (position == -1)
        {
            cout << "Value is not here!" << endl;
            return;
        }

        deleteAtPosition(position);
    }

    int Search(int target)
    {
        if (isEmpty())
            return -1;

        int position = -1;
        ListNode *current = head;

        while (current != nullptr)
        {
            position++;

            if (current->val == target)
                return position;

            current = current->next;
        }

        return -1;
    }

    void Reverse()
    {
        if (isEmpty())
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        tail = head;

        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *previous = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            current->previous = next;
            previous = current;
            current = next;
        }

        head = previous;
    }

    void Print()
    {
        if (isEmpty())
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        ListNode *current = head;

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
    LinkedList *linkedList = new LinkedList();
    linkedList->Add(10);
    linkedList->Add(20);
    linkedList->Add(30);
    linkedList->Add(40);
    linkedList->Add(50);
    linkedList->Print();
    linkedList->Reverse();
    linkedList->Print();
}