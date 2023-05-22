#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* Next;
    Node* Prev;

    Node(int val)
    {
        value= val;
        Next= NULL;
        Prev= NULL;
    }
};

class Stack
{
    Node* head;
    Node* top;
    int count = 0;

public:
    Stack()
    {
        head=NULL;
        top=NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);

        if(head==NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        else
        {
            top->Next = newNode;
            newNode->Prev = top;
            top = newNode;
            count++;
        }
    }

    int pop()
    {
        Node* delNode;
        delNode = top;
        int chk = -1;

        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return chk;
        }
        if(top==head)
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->Prev;
            top->Next = NULL;
        }

        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }

    bool empty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return count;
    }

    int topElement()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow; Stack is empty"<<endl;
        }
        else
        {
            return top->value;
        }
    }
};

