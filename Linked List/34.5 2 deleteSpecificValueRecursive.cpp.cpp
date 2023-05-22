#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value= val;
        next= NULL;
    }
};

void insertAtTail(Node* &head, int val);
void display(Node *head);
Node* deleteSpecificValue(Node* &head, int val);

int main()
{
    Node* head= NULL;

    cout<<"Enter the size of list: ";
    int n;
    cin>>n;

    cout<<"Enter list values: ";
    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        insertAtTail(head, value);
    }
    display(head);

    cout<<"Enter a value to delete: ";
    int val;
    cin>>val;
    head= deleteSpecificValue(head, val);

    display(head);

    return 0;
}

void insertAtTail(Node* &head, int val)
{
    Node *newNode= new Node(val);      // Creating a new node as newNode->value = val and newNode->Next = NULL

    if(head==NULL)
    {
        head= newNode;                 // Inserting the newNode as head
        return;
    }

    Node *temp= head;
    while(temp->next != NULL)          // Condition for finding the last node with next pointer== null
    {
        temp= temp->next;              // Traversing to the next node till loop condition is true
    }

    temp->next= newNode;               // Inserting the newNode as tail
}

void display(Node* head)
{
    //if(head == NULL) return;
    cout<<"\nThe Linked list is: "<<endl;
    while(head != NULL)                   // Condition for finding the last node before node == null
    {
        cout<<head->value;                // Printing the node->value

        if(head->next != NULL)
        {
            cout<<" -> ";
        }

        head= head->next;                    // Traversing to the next node till loop condition is true
    }
    cout<<endl;
}

Node* deleteSpecificValue(Node* &head, int val)
{
    if(head==NULL)
    {
        return head;
    }

    head->next = deleteSpecificValue(head->next, val);

    if(head->value == val)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    else
    {
        return head;
    }
}
