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
void display(Node* head);
void deletionAtHead(Node* &head);

int main()
{
    Node* head= NULL;

    insertAtTail(head, 14);
    insertAtTail(head, 25);
    insertAtTail(head, 33);
    insertAtTail(head, 47);

    display(head);

    deletionAtHead(head);

    cout<<"After deleting 14 ";
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

void display(Node* head)
{
    cout<<"The Linked list is "<<endl;
    while(head != NULL)
    {
        cout<<head->value;
        if(head->Next != NULL)
        {
            cout<<" -> ";
        }
        head= head->Next;
    }
    cout<<endl;
}

void deletionAtHead(Node* &head)
{
    Node* temp= head;
    if(temp != NULL)
    {
        head= temp->Next;
        delete temp;
    }
    else
    {
        cout<<"The list is empty"<<endl;
    }
}
