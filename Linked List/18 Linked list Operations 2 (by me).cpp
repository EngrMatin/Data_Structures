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

struct Test
{
    int position[1000];
};

void insertAtHead(Node* &head, int val);
void insertAtTail(Node* &head, int val);
void display(Node* n);
int countLength(Node* &head);
void insertAtSpecificPosition(Node* &head, int pos, int val);
int searchByValueUnique(Node* &head, int key);
int searchByValueDuplicate(Node* &head, int key);
Test searchByValueDuplicateReturn(Node* &head, int key);
void insertAfterSpecificValue(Node* &head, int searchValue, int value);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head, int position);     // by me
void deleteA_SpecificValue(Node* &head, int val);
void deleteA_SpecificValueDuplicate(Node* &head, int val);

int main()
{
    Node* head= NULL;

    int value;
    cout<<"Choice 1: Insertion at Head"<<endl
        <<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 3: Insertion at Specific Position"<<endl
        <<"Choice 4: Search a value (Unique List)"<<endl
        <<"Choice 5: Search a value (Duplication enabled List)"<<endl
        <<"Choice 6: Insertion after a specific value(Unique List)"<<endl
        <<"Choice 7: Insertion after a specific value(Duplication enabled List)"<<endl
        <<"Choice 8: Deletion at Head"<<endl
        <<"Choice 9: Deletion at Tail"<<endl
        <<"Choice 10: Deletion at Specific Position"<<endl
        <<"Choice 11: Delete a specific value (Unique List)"<<endl
        <<"Choice 12: Delete a specific value (Duplication enabled List)"<<endl
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

            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0]==1)
            {
                cout<<"The value is NOT present in the list"<<endl;
            }
            else
            {
                int size= T.position[0];
                cout<<"The value is at Position: ";
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1)
                    {
                        cout<<", ";
                    }
                }
                cout<<endl;
            }
            break;

        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            insertAfterSpecificValue(head, searchValue, value);
            break;

        case 8:
            deletionAtHead(head);
            break;

        case 9:
            deletionAtTail(head);
            break;

        case 10:
            cout<<"Enter the desired position: ";
            cin>>position;
            deletionAtSpecificPosition(head, position);
            break;

        case 11:
            cout<<"Enter the value to delete: ";
            cin>>value;
            deleteA_SpecificValue(head, value);
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

    cout<<"\nThe Length of the Linked list is "<<countLength(head)<<endl;

    return 0;
}

void insertAtHead(Node* &head, int val)
{
    Node* newNode= new Node(val);      // Step 1: newNode creation
    newNode->Next= head;               // Step 2: Update newNode->Next
    head= newNode;                     // Step 3: Update head

    display(head);
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

    display(head);
}

void display(Node* n)
{
    cout<<"\nThe Linked list is "<<endl;
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

    display(head);
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
                cout<<", ";
            }
        }
        cout<<endl;
    }
}

Test searchByValueDuplicateReturn(Node* &head, int key)
{
    Node* temp= head;
    Test T;
    int k=1;
    int count= 1;

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            //cout<<count<<" ";
            T.position[k]= count;
            k++;
        }
        temp= temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void insertAfterSpecificValue(Node* &head, int searchValue, int value)
{
    //Step 1: Search the position of the value
    int position;
    position = searchByValueUnique(head, searchValue);
    //Step 2: Insert the value at the position+1
    insertAtSpecificPosition(head, position+1, value);
}

void deletionAtHead(Node* &head)
{
    Node* temp= head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    head= temp->Next;
    delete temp;
    //display(head);
}

void deletionAtTail(Node* &head)
{
    Node* temp= head;
    if(temp==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    else if(temp->Next == NULL)
    {
        deletionAtHead(head);
        return;
    }

    while(temp->Next->Next != NULL)
    {
        temp= temp->Next;
    }
    Node* delNode= temp->Next;
    temp->Next= NULL;

    delete delNode;
    //display(head);
}

void deletionAtSpecificPosition(Node* &head, int pos)     // by me
{
    Node* temp= head;
    int len= countLength(head);
    if(pos<1)
    {
        cout<<"Please enter a valid position >= 1"<<endl;
        return;
    }
    else if(pos>len)
    {
        cout<<"This position is not available in the list"<<endl;
        return;
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            temp= temp->Next;
        }

        if(pos == 1)
        {
            deletionAtHead(head);
            return;
        }
        else
        {
            Node* delNode= temp->Next;
            temp->Next= delNode->Next;
            delete delNode;
        }
    }
}

void deleteA_SpecificValue(Node* &head, int val)
{
    int position;
    position = searchByValueUnique(head, val);
    if(position == -1)
    {
       cout<<"The value is NOT present in the list"<<endl;
       return;
    }
    deletionAtSpecificPosition(head, position);
}

void deleteA_SpecificValueDuplicate(Node* &head, int val)
{
    Test T;
    T = searchByValueDuplicateReturn(head, val);
    if(T.position[0]==1)
    {
        cout<<"The value is NOT present in the list"<<endl;
        return;
    }
    else
    {
        int size= T.position[0];
//        for(int i=0; i<size; i++)
//        {
//            cout<<T.position[i]<<" ";
//        }
        for(int i=1; i<size; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]);

            for(int i=1; i<size; i++)
            {
                T.position[i]--;
            }

//            for(int i=0; i<size; i++)
//            {
//                cout<<T.position[i]<<" ";
//            }
        }
    }
}
