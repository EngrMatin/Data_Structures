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
void insertAtSpecificPosition(Node* &head, int pos, int val);
int searchByValueUnique(Node* &head, int key);
void insertAfterSpecificValue(Node* &head, int searchValue, int value);

int main()
{
    Node* head= NULL;

    insertAtTail(head, 14);
    insertAtTail(head, 25);
    insertAtTail(head, 33);
    insertAtTail(head, 47);

    display(head);

    insertAfterSpecificValue(head, 33, 40);

    cout<<"After inserting 40 in between 33 and 47 ";
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

void insertAtSpecificPosition(Node* &head, int pos, int val)
{
    Node* temp= head;

    int i=0;
    while(i<pos-2)
    {
        temp= temp->Next;
        i++;
    }

    Node* newNode= new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node* &head, int key)
{
    Node* temp= head;
    int count= 1;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp->value != key)
    {
        if(temp->Next == NULL)
        {
            return -1;
        }
        temp= temp->Next;
        count++;
    }
    return count;
}

void insertAfterSpecificValue(Node* &head, int searchValue, int value)
{
    int position;
    position = searchByValueUnique(head, searchValue);

    insertAtSpecificPosition(head, position+1, value);
}

