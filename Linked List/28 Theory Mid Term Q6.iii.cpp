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

void insertAtHead(Node* &head, int val);
void insertAtTail(Node* &head, int val);
void display(Node* n);

int main()
{
    Node* head= NULL;

    insertAtTail(head, 14);
    insertAtTail(head, 25);
    insertAtTail(head, 33);
    insertAtTail(head, 47);

    display(head);

    return 0;
}

void insertAtTail(Node* &head, int val)
{
    Node* newNode= new Node(val);

    if(head==NULL)
    {
        head= newNode;
        newNode->Next = head;
        return;
    }

    Node* temp= head;
    while(temp->Next != head)
    {
        temp= temp->Next;
    }

    newNode->Next = head;             // newNode->Next = temp->Next
    temp->Next= newNode;
}

void display(Node* head)
{
    if(head == NULL)
    {
        cout<<"\nThe Linked list is Empty"<<endl;
        return;
    }

    Node* temp = head;
    do
    {
        cout<<temp->value;
        temp = temp->Next;

        if(temp != head)
        {
            cout<<" -> ";
        }
    }
    while(temp != head);
    cout<<endl;
}
