#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int val;
    StackNode *next;

    StackNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class Stack
{
public:
    StackNode *top;

    Stack()
    {
        this->top = nullptr;
    }

    void Push(int val)
    {
        StackNode *node = new StackNode(val);
        node->next = top;
        top = node;
    }

    void Pop()
    {
        if (!isEmpty())
        {
            StackNode *current = top->next;
            top = current;
        }
    }

    int getTop()
    {
        return (!isEmpty()) ? top->val : -1;
    }

    void Print()
    {
        StackNode *current = top;

        while (current != nullptr)
        {
            cout << current->val << endl;
            current = current->next;
        }

        cout << endl;
    }

    bool Search(int val)
    {
        StackNode *current = top;

        while (current != nullptr)
        {
            if (current->val == val)
                return true;

            current = current->next;
        }

        return false;
    }

    int Size()
    {
        int result = 0;
        StackNode *current = top;

        while (current != nullptr)
        {
            result++;
            current = current->next;
        }

        return result;
    }

    bool isEmpty()
    {
        return top == nullptr;
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