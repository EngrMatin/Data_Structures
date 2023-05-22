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
void display(Node* n);

int main()
{
    Node* head= NULL;

    int n;
    char choice= 'y';
    while(choice=='y')
    {
        cout<<"Enter the value: ";
        cin>>n;
        insertAtTail(head, n);
        cout<<"Do you want to continue: (y/n) ";
        cin>>choice;
    }

    display(head);

    return 0;
}

void insertAtTail(Node* &head, int val)
{
    Node* newNode= new Node(val);      // Creating a new node as newNode->value = val and newNode->Next = NULL

    if(head==NULL)
    {
        head= newNode;                 // Inserting the newNode as head
        return;
    }

    Node* temp= head;
    while(temp->Next != NULL)          // Condition for finding the last node
    {
        temp= temp->Next;              // Traversing to the next node till loop condition is true
    }

    temp->Next= newNode;               // Inserting the newNode as tail
}

void display(Node* n)
{
    while(n != NULL)
    {
        cout<<n->value;                // Printing the node->value
        if(n->Next != NULL)
        {
            cout<<" -> ";
        }
        n= n->Next;                    // Traversing to the next node till loop condition is true
    }
    cout<<endl;
}
