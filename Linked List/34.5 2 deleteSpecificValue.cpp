#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value= val;
        Next= NULL;
    }
};

struct Test
{
    int position[10001];
};

void insertAtTail(Node* &head, int val);
void display(Node *head);
Node* deleteA_SpecificValueDuplicate(Node* &head, int val);

int main()
{
    Node* head= NULL;

    int value;
    cout<<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 12: Delete a specific value (Duplication enabled List)"<<endl
        <<"Choice 0: Exit"<<endl;
    cout<<"\nEnter your Choice: ";

    int choice, position;
    cin>>choice;

    while(choice != 0)
    {
        switch(choice)
        {

        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head, value);
            break;

        case 12:
            cout<<"Enter the value to delete: ";
            cin>>value;
            deleteA_SpecificValueDuplicate(head, value);
            break;

        default:
            break;
        }

        cout<<"\nNext Choice: ";
        cin>>choice;
    }

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
    while(temp->Next != NULL)          // Condition for finding the last node with next pointer== null
    {
        temp= temp->Next;              // Traversing to the next node till loop condition is true
    }

    temp->Next= newNode;               // Inserting the newNode as tail
}

void display(Node* head)
{
    cout<<"\nThe Linked list is: "<<endl;
    while(head != NULL)                   // Condition for finding the last node before node == null
    {
        cout<<head->value;                // Printing the node->value

        if(head->Next != NULL)
        {
            cout<<" -> ";
        }

        head= head->Next;                    // Traversing to the next node till loop condition is true
    }
    cout<<endl;
}

int countLength(Node* &head)
{
    int count= 0;
    Node *temp= head;

    while(temp != NULL)
    {
        count++;
        temp= temp->Next;
    }
    return count;
}

Test searchByValueDuplicateReturn(Node* &head, int key)
{
    Node *temp= head;
    Test T;
    int k=1;
    int count= 1;

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            T.position[k]= count;
            k++;
        }
        temp= temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void deletionAtSpecificPosition(Node* &head, int position)
{
    Node *temp= head;

    if(temp != NULL && position <= countLength(head))
    {
        if(position == 1)
        {
            head = temp->Next;
            delete temp;
        }
        else
        {
            int i=1;
            while(i<position-1)
            {
                temp= temp->Next;
                i++;
            }
            Node *delNode= temp->Next;
            temp->Next= delNode->Next;      //temp->Next= temp->Next->Next;
            delete delNode;
        }
    }
    else
    {
        if(position > countLength(head))
        {
            cout<<"Position Out of Bound"<<endl;
        }
        else
        {
            cout<<"The list is empty"<<endl;
        }
    }
}

Node* deleteA_SpecificValueDuplicate(Node* &head, int val)
{
    Test T;
    T = searchByValueDuplicateReturn(head, val);
    if(T.position[0]==1)
    {
        cout<<"The value is NOT present in the list"<<endl;
        return head;
    }
    else
    {
        int size= T.position[0];
        for(int i=1; i<size; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]);

            for(int i=1; i<size; i++)
            {
                T.position[i]--;
            }
        }
    }

    return head;
}

