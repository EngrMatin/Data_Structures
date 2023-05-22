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
void deleteNNodesAfterMNodes(Node* &head, int m, int n);

int main()
{
    Node* head= NULL;

    int k, m, n;
    cin>>k>>m>>n;

    for(int i=0; i<k; i++)
    {
        int value;
        cin>>value;
        insertAtTail(head, value);
    }
    //display(head);

    deleteNNodesAfterMNodes(head, m, n);

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
    //cout<<"\nThe Linked list is "<<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->Next != NULL)
        {
            cout<<" -> ";
        }
        temp = temp->Next;
    }
    cout<<endl;
}

void deleteNNodesAfterMNodes(Node* &head, int m, int n)
{
    Node* current= head;
    Node* temp;
    int count=0;

    while(current)
    {
        for(count=1; count<m && current != NULL; count++)
        {
            current = current->Next;
        }

        if(current == NULL)
        {
            return;
        }

        temp = current->Next;
        for(count=1; count<=n && temp != NULL; count++)
        {
            Node* delNode= temp;
            temp = temp->Next;
            delete delNode;
        }
        current->Next = temp;
        current = temp;
    }
}
