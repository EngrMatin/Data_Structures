#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode* Next;
    doublyNode* Prev;

    doublyNode(int val)
    {
        value= val;
        Next= NULL;
        Prev= NULL;
    }
};

void insertAtHead(doublyNode* &head, int val);
void insertAtTail(doublyNode* &head, int val);
void display(doublyNode* n);
int countLength(doublyNode* &head);
void displayReverse(doublyNode* &head);


int main()
{
    doublyNode* head= NULL;

    int value;
    cout<<"Choice 1: Insertion at Head"<<endl
        <<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 3: Reverse Print"<<endl
        <<"Choice 0: Exit"<<endl;

    cout<<"\nEnter your Choice: ";

    int choice, position;
    cin>>choice;

    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head, value);
            break;

        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head, value);
            break;

        case 3:
            displayReverse(head);
            break;

        default:
            break;
        }

        cout<<"\nNext Choice: ";
        cin>>choice;
    }

    cout<<"\nThe Doubly Linked list is"<<endl;
    display(head);

    cout<<"\nThe Length of the Doubly Linked list is "<<countLength(head)<<endl;

    return 0;
}

void insertAtHead(doublyNode* &head, int val)
{
    doublyNode* newNode= new doublyNode(val);   // Step 1: newNode creation
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    head->Prev = newNode;                       // Step 2: Update head->Prev
    newNode->Next= head;                        // Step 3: Update newNode->Next
    head= newNode;                              // Step 4: Update head
}

void insertAtTail(doublyNode* &head, int val)
{
    doublyNode* newNode= new doublyNode(val);

    if(head==NULL)
    {
        head= newNode;
        return;
    }

    doublyNode* temp= head;
    while(temp->Next != NULL)
    {
        temp= temp->Next;
    }

    temp->Next= newNode;
    newNode->Prev= temp;
}

void display(doublyNode* n)
{
    while(n != NULL)
    {
        cout<<n->value;
        if(n->Next != NULL)
        {
            cout<<" <--> ";
        }
        n= n->Next;
    }
    cout<<endl;
}

void displayReverse(doublyNode* &head)
{
    doublyNode* temp= head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }

    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->Prev != NULL)
        {
            cout<<" <--> ";
        }
        temp = temp->Prev;
    }
    cout<<endl;
}

int countLength(doublyNode* &head)
{
    int count= 0;
    doublyNode* temp= head;

    while(temp != NULL)
    {
        count++;
        temp= temp->Next;
    }
    return count;
}

