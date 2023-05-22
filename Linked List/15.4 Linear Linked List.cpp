#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void display(Node *n);

int main()
{
    Node *head= new Node(5);
    Node *second= new Node(6);
    Node *third= new Node(7);
    Node *fourth= new Node(8);

    //head->value= 1;
    //second->value= 2;
    //third->value= 3;
    //fourth->value= 4;

    head->Next= second;
    second->Next= third;
    third->Next= fourth;
    fourth->Next= NULL;

    display(head);

    return 0;
}

void display(Node *n)
{
    while(n != NULL)
    {
        cout<<n->value;
        if(n->Next != NULL)
        {
            cout<<" -> ";
        }
        n= n->Next;
    }
    cout<<endl;
}
