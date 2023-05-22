#include<bits/stdc++.h>
using namespace std;

template<typename N> class Node
{
public:
    N value;
    Node* Next;
    Node* Prev;

    Node(N val)
    {
        value= val;
        Next= NULL;
        Prev= NULL;
    }
};

template<typename S> class Stack
{
    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:
    Stack()
    {
        head=NULL;
        top=NULL;
    }

    void push(S val)
    {
        Node <S> *newNode = new Node <S> (val);

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
            top = newNode;         //top = top->Next;
            count++;
        }
    }

    S pop()
    {
        Node <S> *delNode;
        delNode = top;
        S chk;

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

    S topElement()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow; Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return top->value;
        }
    }
};

