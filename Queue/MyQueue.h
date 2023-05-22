#include<bits/stdc++.h>

using namespace std;

class Node
{
public:

    int value;
    Node *next;

public:
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = rear->next;
    }

    int pop()
    {
        int chk = -1;
        if(rear == NULL)
        {
            cout<<"Queue Underflow; the Queue is empty"<<endl;
            return chk;
        }

        Node *delNode;
        delNode = front;
        front = front->next;
        if(front == NULL)
        {
            rear = NULL;
        }

        chk = delNode->value;
        delete delNode;
        return chk;
    }

    int Front()
    {
        int chk;
        chk = front->value;
        return chk;
    }

    int Back()
    {
        int chk;
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
