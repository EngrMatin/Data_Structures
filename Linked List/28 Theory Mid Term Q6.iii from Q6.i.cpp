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
        newNode->Next = head;    // link newNode with head
        return;
    }

    Node* temp= head;
    while(temp->Next != head)   //for linear list: temp->Next != NULL
    {
        temp= temp->Next;
    }

    newNode->Next = head;       // link newNode with head
    temp->Next= newNode;
}

void display(Node* head)
{
    cout<<"The Linked list is "<<endl;
//    while(head != NULL)
//    {
//        cout<<head->value;
//        if(head->Next != NULL)
//        {
//            cout<<" -> ";
//        }
//        head= head->Next;
//    }

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
