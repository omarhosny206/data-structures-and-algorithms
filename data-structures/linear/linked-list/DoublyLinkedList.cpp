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
        next = nullptr;
        previous = nullptr;
    }

    ListNode(int val)
    {
        this->val = val;
        next = nullptr;
        previous = nullptr;
    }

    ListNode(int val, ListNode *next, ListNode *previous)
    {
        val = val;
        next = next;
        previous = previous;
    }
};

class DoublyLinkedList
{
public:
    ListNode *head;
    ListNode *tail;
    int size;

    DoublyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }

    DoublyLinkedList(vector<int> &values)
    {
        for (int &val : values)
            add(val);
    }

    void add(int val)
    {
        ListNode *newNode = new ListNode(val);

        if (isEmpty())
            head = tail = newNode;

        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }

        size++;
    }

    void addAtFirst(int val)
    {
        ListNode *newNode = new ListNode(val);

        if (isEmpty())
            head = tail = newNode;

        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void addAtPosition(int val, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Out Of Boundary" << endl;
            return;
        }

        if (position == 0)
        {
            addAtFirst(val);
            return;
        }

        else if (position == size)
        {
            add(val);
            return;
        }

        ListNode *newNode = new ListNode(val);
        ListNode *current = head;

        while (--position)
            current = current->next;

        newNode->next = current->next;
        current->next->previous = newNode;
        current->next = newNode;
        newNode->previous = current;

        size++;
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        if (size == 1)
            head = tail = nullptr;

        else
        {
            ListNode *current = head;

            while (current->next != tail)
                current = current->next;

            tail->previous = nullptr;
            current->next = nullptr;
            tail = current;
        }

        size--;
    }

    void removeAtFirst()
    {
        if (isEmpty())
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        if (size == 1)
            head = tail = nullptr;

        else
        {
            ListNode *current = head->next;
            current->previous = nullptr;
            head = current;
        }

        size--;
    }

    void removeAtPosition(int position)
    {
        if (isEmpty())
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        if (position == 0)
        {
            removeAtFirst();
            return;
        }

        else if (position == size - 1)
        {
            remove();
            return;
        }

        ListNode *current = head;

        while (--position)
            current = current->next;

        ListNode *nodeToRemove = current->next;

        current->next = nodeToRemove->next;
        nodeToRemove->next->previous = current;

        size--;
    }

    void removeByValue(int val)
    {
        int position = search(val);

        if (position == -1)
        {
            cout << "Value doesn't exist" << endl;
            return;
        }

        removeAtPosition(position);
    }

    int search(int target)
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

    void reverse()
    {
        if (isEmpty())
        {
            cout << "Linked List is empty" << endl;
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

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print()
    {
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
    DoublyLinkedList *linkedList = new DoublyLinkedList();
    linkedList->add(10);
    linkedList->add(20);
    linkedList->add(30);
    linkedList->add(40);
    linkedList->add(50);

    linkedList->print();

    linkedList->reverse();
    linkedList->print();
}