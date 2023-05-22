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

void insertAtHead(Node* &head, int val);
void insertAtTail(Node* &head, int val);
void display(Node* n);
void reversedListPrint(Node* n);

int main()
{
    Node* head= NULL;

    int n;
    cout<<"Choice 1: Insertion at Head"<<endl<<"Choice 2: Insertion at Tail"<<endl<<"Choice 3: Exit"<<endl;
    int choice= 2;
    while(choice== 1 || choice== 2)
    {
        cout<<"Enter the value: ";
        cin>>n;
        if(choice==1)
        {
            insertAtHead(head, n);
        }
        else if(choice==2)
        {
            insertAtTail(head, n);
        }

        cout<<"Next Choice: ";
        cin>>choice;
    }

    display(head);
    reversedListPrint(head);

    return 0;
}

void insertAtHead(Node* &head, int val)
{
    Node* newNode= new Node(val);      // Step 1: newNode creation
    newNode->Next= head;               // Step 2: Update newNode->Next
    newNode->Prev= NULL;
    head= newNode;                     // Step 3: Update head
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
    newNode->Prev= temp->Prev;
}

void display(Node* n)
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

void reversedListPrint(Node* n1)
{
    while(n1 != NULL)
    {
        cout<<n1->value;
        if(n1->Prev != NULL)
        {
            cout<<" -> ";
        }
        n1= n1->Prev;
    }
    cout<<endl;
}
