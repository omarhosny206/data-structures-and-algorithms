#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int val;
    StackNode *next;

    StackNode()
    {
        next = nullptr;
    }

    StackNode(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class Stack
{
private:
    StackNode *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    Stack(int val)
    {
        top = new StackNode(val);
    }

    Stack(vector<int> &values)
    {
        for (int &val : values)
            push(val);
    }

    void push(int val)
    {
        StackNode *newTop = new StackNode(val);
        newTop->next = top;
        top = newTop;
        size++;
    }

    int pop()
    {
        if (isEmpty())
            throw runtime_error("Cannot pop, the stack is empty.");

        StackNode *temp = top;
        top = top->next;
        size--;
        return temp->val;
    }

    bool search(int target)
    {
        StackNode *current = top;

        while (current != nullptr)
        {
            if (current->val == target)
                return true;

            current = current->next;
        }

        return false;
    }

    int getTop()
    {
        if (isEmpty())
            throw runtime_error("Cannot get top, the stack is empty.");

        return top->val;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        StackNode *current = top;

        while (current != nullptr)
        {
            cout << current->val << endl;
            current = current->next;
        }
    }
};

int main()
{
    vector<int> values = {5, 10, 15, 20, 25};
    Stack *stack = new Stack(values);

    stack->push(30);

    cout << "Top: " << stack->getTop() << endl;

    cout << "Print: " << endl;
    stack->print();
    cout << endl;

    cout << "Search for 10: " << stack->search(10) << endl;
    cout << "Search for 8: " << stack->search(8) << endl;
    cout << endl;

    cout << "Pop: " << stack->pop() << endl;
    cout << "Top: " << stack->getTop() << endl;

    cout << "Pop: " << stack->pop() << endl;
    cout << "Pop: " << stack->pop() << endl;
    cout << "Pop: " << stack->pop() << endl;
    cout << "Pop: " << stack->pop() << endl;

    cout << "Top: " << stack->getTop() << endl;
}