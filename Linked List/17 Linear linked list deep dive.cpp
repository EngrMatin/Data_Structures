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
int countLength(Node* &head);
void insertAtSpecificPosition(Node* &head, int pos, int val);
int searchByValueUnique(Node* &head, int key);
int searchByValueDuplicate(Node* &head, int key);

int main()
{
    Node* head= NULL;

    int value;
    cout<<"Choice 1: Insertion at Head"<<endl
        <<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 3: Insertion at Specific Position"<<endl
        <<"Choice 4: Search a value (Unique List)"<<endl
        <<"Choice 5: Search a value (Duplication enabled List)"<<endl
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
            cout<<"Enter the desired position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtSpecificPosition(head, position, value);
            break;

        case 4:
            cout<<"Enter the value to search: ";
            cin>>value;
            position= searchByValueUnique(head, value);
            if(position != -1)
            {
                cout<<"The value is at Position "<<position<<endl;
            }
            else
            {
                cout<<"The value is NOT present in the list"<<endl;
            }
            break;

        case 5:
            cout<<"Enter the value to search: ";
            cin>>value;
            searchByValueDuplicate(head, value);
            break;

        default:
            break;
        }

        cout<<"\nNext Choice: ";
        cin>>choice;
    }

    cout<<"\nThe Linked list is "<<endl;
    display(head);

    cout<<"\nThe Length of the Linked list is "<<countLength(head)<<endl;

    return 0;
}

void insertAtHead(Node* &head, int val)
{
    Node* newNode= new Node(val);      // Step 1: newNode creation
    newNode->Next= head;               // Step 2: Update newNode->Next
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

int countLength(Node* &head)
{
    int count= 0;
    Node* temp= head;

    while(temp != NULL)
    {
        count++;
        temp= temp->Next;
    }
    return count;
}

void insertAtSpecificPosition(Node* &head, int pos, int val)
{
    int i=0;
    Node* temp= head;

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

int searchByValueDuplicate(Node* &head, int key)
{
    Node* temp= head;
    int size;
    size= countLength(head);
    int position[size+1], k=1;
    int count= 1;
    int flag= 0;

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            //cout<<count<<" ";
            position[k]= count;
            k++;
            flag=1;
        }
        temp= temp->Next;
        count++;
    }

    if(flag==0)
    {
        cout<<"The value is NOT present in the list"<<endl;
    }
    else
    {
        position[0]= k;
        cout<<"The value is at Position ";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1)
            {
                cout<<",";
            }
        }
        cout<<endl;
    }
}
