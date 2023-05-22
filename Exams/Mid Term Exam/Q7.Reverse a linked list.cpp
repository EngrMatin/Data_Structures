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
Node* reverseKNodes(Node* &head, int k);

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
    //display(head);

    int k;
    cin>>k;

    head = reverseKNodes(head, k);
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

void display(Node* n)
{
    //cout<<"\nThe Linked list is "<<endl;
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

Node* reverseKNodes(Node* &head, int k)
{
    Node* prev = NULL;
    Node* current = head;

    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return head;
    }

    Node* next = head->Next;
    int count=0;

    while(current!=NULL && count < k)
    {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->Next = reverseKNodes(next, k);
    }

    return prev;
}
