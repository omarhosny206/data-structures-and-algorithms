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

    void push(int val)
    {
        StackNode *newTop = new StackNode(val);
        newTop->next = top;
        top = newTop;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        top = top->next;
        size--;
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
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

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
    Stack *stack = new Stack();
    stack->pop();
    stack->push(5);
    stack->push(10);
    stack->push(15);
    stack->push(20);
    stack->push(25);

    cout << stack->search(10) << endl;
    cout << stack->search(8) << endl;
    cout << endl;

    stack->pop();
    cout << stack->getTop() << endl
         << endl;

    stack->print();
    cout << endl
         << endl;

    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();

    cout << stack->getTop() << endl;
}