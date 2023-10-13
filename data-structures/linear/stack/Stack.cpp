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

    StackNode(int val, StackNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

class Stack
{
private:
    StackNode *top;

public:
    Stack()
    {
    }

    Stack(int val)
    {
        top = new StackNode(val);
    }

    void push(int val)
    {
        StackNode *node = new StackNode(val, top);
        top = node;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }

        StackNode *current = top->next;
        top = current;
    }

    bool Search(int target)
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
            cout << "Stack is empty --> ";
            return -1;
        }

        return top->val;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void Print()
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
    stack->Push(5);
    stack->Push(10);
    stack->Push(15);
    stack->Push(20);
    stack->Push(25);
    cout << stack->Search(10) << endl;
    cout << stack->Search(8) << endl;
    cout << endl;
    stack->Pop();
    cout << stack->getTop() << endl
         << endl;
    stack->Print();
    cout << endl
         << endl;
    stack->Pop();
    stack->Pop();
    stack->Pop();
    stack->Pop();
    cout << stack->getTop() << endl;
}