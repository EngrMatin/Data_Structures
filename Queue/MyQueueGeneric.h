#include<bits/stdc++.h>

using namespace std;

template <typename N> class Node
{
public:

    N value;
    Node *Next;

public:
    Node(N val)
    {
        value = val;
        Next = NULL;
    }
};

template <typename Q> class Queue
{
    Node <Q> *front;
    Node <Q> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(Q val)
    {
        Node <Q> *newNode = new Node <Q> (val);

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->Next = newNode;
        rear = rear->Next;
    }

    Q pop()
    {
        Q chk;
        if(rear == NULL)
        {
            cout<<"Queue Underflow; the Queue is empty"<<endl;
            return chk;
        }

        Node <Q> *delNode;
        delNode = front;
        front = front->Next;
        if(front == NULL)
        {
            rear = NULL;
        }

        chk = delNode->value;
        delete delNode;
        return chk;
    }

    Q Front()
    {
        Q chk;
        chk = front->value;
        return chk;
    }

    Q Back()
    {
        Q chk;
        chk = rear->value;
        return chk;
    }

    bool empty()
    {
        if(front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
