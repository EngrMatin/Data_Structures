#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* Next;

    Node(int val)
    {
        value= val;
        Next= NULL;
    }
};

void insertAtTail(Node* &head, int val);
Node* replaceEvenValueByMinusOne(Node* &head);
void display(Node* n);

int main()
{
    Node* head= NULL;

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        insertAtTail(head, value);
    }
    display(head);

    head= replaceEvenValueByMinusOne(head);
    display(head);

    return 0;
}

void insertAtTail(Node* &head, int val)
{
    Node* newNode= new Node(val);

    if(head==NULL)
    {
        head= newNode;
        return;
    }

    Node* temp= head;
    while(temp->Next != NULL)
    {
        temp= temp->Next;
    }

    temp->Next= newNode;
}

Node* replaceEvenValueByMinusOne(Node* &head)
{
    Node* temp= head;

    while(temp != NULL)
    {
        if(temp->value%2==0)
        {
            temp->value= -1;
        }

        temp= temp->Next;
    }

    return head;
}

void display(Node* n)
{
    cout<<"\nThe Linked list is "<<endl;
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
