#include <bits/stdc++.h>
using namespace std;

class Logger
{
public:
    static void info(string message)
    {
        cout << message << endl;
    }
};

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->next = nullptr;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    ListNode *head;
    int size;

public:
    SinglyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    SinglyLinkedList(vector<int> &values)
    {
        for (int &val : values)
            add(val);
    }

    void add(int val)
    {
        Logger::info("Add " + to_string(val));
        ListNode *newNode = new ListNode(val);

        if (isEmpty())
            head = newNode;

        else
        {
            ListNode *current = head;

            while (current->next != nullptr)
                current = current->next;

            current->next = newNode;
        }

        size++;
    }

    void addAtFirst(int val)
    {
        Logger::info("Add " + to_string(val) + " at first");
        ListNode *newNode = new ListNode(val);

        if (isEmpty())
            head = newNode;

        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void addAtPosition(int val, int position)
    {
        if (position < 0 || position > size)
            throw runtime_error("Cannot add at position (" + to_string(position) + "), out of the linked-list's boundary.");

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

        Logger::info("Add " + to_string(val) + " at position (" + to_string(position) + ")");
        ListNode *newNode = new ListNode(val);
        ListNode *current = head;

        while (--position)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    void remove()
    {
        if (isEmpty())
            throw runtime_error("Cannot remove, the linked-list  is empty.");

        Logger::info("Remove");

        if (size == 1)
            head = nullptr;

        else
        {
            ListNode *current = head;

            while (current->next->next != nullptr)
                current = current->next;

            current->next = nullptr;
        }

        size--;
    }

    void removeAtFirst()
    {
        if (isEmpty())
            throw runtime_error("Cannot remove at first, the linked-list is empty.");

        Logger::info("Remove at first");

        if (size == 1)
            head = nullptr;

        else
            head = head->next;

        size--;
    }

    void removeAtPosition(int position)
    {
        if (position < 0 || position >= size)
            throw runtime_error("Cannot remove at position (" + to_string(position) + "), out of the linked-list's boundary.");

        if (isEmpty())
            throw runtime_error("Cannot remove at position (" + to_string(position) + "), the linked-list is empty.");

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

        Logger::info("Remove at position (" + to_string(position) + ")");

        ListNode *current = head;

        while (--position)
            current = current->next;

        ListNode *nodeToRemove = current->next;
        current->next = nodeToRemove->next;

        size--;
    }

    void removeByValue(int val)
    {
        int position = search(val);

        if (position == -1)
            throw runtime_error("Cannot remove by value (" + to_string(val) + "), the value doesn't exist in the linked-list.");

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
            throw runtime_error("Cannot reverse, the linked-list is empty.");

        Logger::info("Reverse");

        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *previous = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
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
        Logger::info("Print");
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
    vector<int> values = {5, 10, 15, 20, 25, 30};
    SinglyLinkedList *linkedList = new SinglyLinkedList(values);

    linkedList->print();

    linkedList->addAtFirst(0);
    linkedList->add(35);

    linkedList->print();

    linkedList->addAtPosition(100, 3);
    linkedList->addAtPosition(200, 5);

    linkedList->print();

    linkedList->removeAtFirst();
    linkedList->remove();

    linkedList->print();

    linkedList->removeAtPosition(4);
    linkedList->removeByValue(25);

    linkedList->print();

    linkedList->reverse();
    linkedList->print();
}