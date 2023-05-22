#include<bits/stdc++.h>        // Only 6 function has been updated
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
//void insertAtSpecificPosition(Node* &head, int pos, int val);
//int searchByValueUnique(Node* &head, int key);
//void searchByValueDuplicate(Node* &head, int key);
//Test searchByValueDuplicateReturn(Node* &head, int key);
//void insertAfterSpecificValue(Node* &head, int searchValue, int value);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
//void deletionAtSpecificPosition(Node* &head, int position);
//void deleteA_SpecificValue(Node* &head, int val);
//void deleteA_SpecificValueDuplicate(Node* &head, int val);
//Node* reverseNonRecursive(Node* &head);
//Node* reverseRecursive(Node* &head);
//int findMid(Node* &head);
//void makeCycle(Node* &head, int pos);
//bool detectCycle(Node* &head);
//void removeCycle(Node* &head);

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
        <<"Choice 13: Reversal of a list (Non-Recursive)"<<endl
        <<"Choice 14: Reversal of a list (Recursive)"<<endl
        <<"Choice 15: Finding the Mid by Slow Fast Pointers"<<endl
        <<"Choice 16: Make a Cycle at a specific position"<<endl
        <<"Choice 17: Detect Cycle in the list"<<endl
        <<"Choice 18: Detect and Remove a Cycle in the list"<<endl
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
            if(head==NULL)
            {
                cout<<"The list is empty"<<endl;
                break;
            }
            cout<<"Enter the desired position: ";
            cin>>position;

            deletionAtSpecificPosition(head, position);
            //cout<<endl;
            //display(head);
            break;

        case 11:
            cout<<"Enter the value to delete: ";
            int delValue;
            cin>>delValue;
            deleteA_SpecificValue(head, delValue);
            break;

        case 12:
            cout<<"Enter the value to delete: ";
            cin>>value;
            deleteA_SpecificValueDuplicate(head, value);
            break;

        case 13:
            head = reverseNonRecursive(head);
            break;

        case 14:
            head = reverseRecursive(head);
            break;

        case 15:
            int mid;
            mid = findMid(head);
            if(mid == -1)
            {
                cout<<"The list is empty"<<endl;
            }
            else
            {
                cout<<"The mid value is "<<mid<<endl;
            }
            break;

        case 16:
            cout<<"Enter the desired position to create cycle: ";
            cin>>position;
            makeCycle(head, position);
            break;

        case 17:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus==true)
            {
                cout<<"There is a cycle in the list"<<endl;
            }
            else
            {
                cout<<"There is NO cycle in the list"<<endl;
            }
            break;

        case 18:
            cycleStatus = detectCycle(head);
            if(cycleStatus==true)
            {
                removeCycle(head);
            }
            else
            {
                cout<<"There is NO cycle in the list"<<endl;
            }
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

    if(head==NULL)
    {
        head= newNode;
        newNode->Next = head;
        return;
    }

    Node* temp= head;                  // Step 3: Find the tail before update the head
    while(temp->Next != head)
    {
        temp= temp->Next;
    }

    head= newNode;                    // Step 4: Update head

    temp->Next = head;                // Step 5: Update the tail with new head

    //display(head);
}

void insertAtTail(Node* &head, int val)
{
    Node* newNode= new Node(val);

    if(head==NULL)
    {
        head= newNode;
        newNode->Next = head;
        return;
    }

    Node* temp= head;
    while(temp->Next != head)
    {
        temp= temp->Next;
    }

    newNode->Next = head;             // newNode->Next = temp->Next
    temp->Next= newNode;


    //display(head);
}

void display(Node* head)
{
    if(head == NULL)
    {
        cout<<"\nThe Linked list is Empty"<<endl;
        return;
    }

    Node* temp = head;
    do
    {
        cout<<temp->value;
        temp = temp->Next;

        if(temp != head)
        {
            cout<<" -> ";
        }
    }
    while(temp != head);
    cout<<endl;
}

int countLength(Node* &head)
{
    int count= 0;
    Node* temp= head;

    do
    {
        count++;
        temp= temp->Next;
    }
    while(temp != head);
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

    //display(head);
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

void searchByValueDuplicate(Node* &head, int key)
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
    if(temp != NULL)
    {
        Node* delNode = temp;

        while(temp->Next != head)
        {
            temp = temp->Next;
        }

        temp->Next = delNode->Next;

        head= delNode->Next;
        delete delNode;
    }
    else
    {
        cout<<"The list is empty"<<endl;
    }
}

void deletionAtTail(Node* &head)
{
    Node* temp= head;
    if(temp != NULL && temp->Next != head)
    {
        while(temp->Next->Next != head)
        {
            temp= temp->Next;
        }
        Node* delNode= temp->Next;
        temp->Next= head;
        delete delNode;
    }
    else
    {
        if(temp == NULL)
        {
            cout<<"The list is empty"<<endl;
        }
        else             //Head is Tail
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node* &head, int position)
{
    Node* temp= head;

    if(temp != NULL && position <= countLength(head))
    {
        if(position == 1)
        {
            deletionAtHead(head);
        }
        else if(position == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i=1;
            while(i<position-1)
            {
                temp= temp->Next;
                i++;
            }
            Node* delNode= temp->Next;
            temp->Next= delNode->Next;
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

void deleteA_SpecificValue(Node* &head, int value)
{
    int position;
    position = searchByValueUnique(head, value);
    if(position == -1)
    {
       cout<<"The value is NOT present in the list"<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
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
        for(int i=1; i<size; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]);

            for(int i=1; i<size; i++)
            {
                T.position[i]--;
            }
        }
    }
}

Node* reverseNonRecursive(Node* &head)
{
    Node* prev = NULL;
    Node* current = head;

    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return head;
    }

    Node* next = head->Next;

    while(1)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if(current==NULL)
        {
            break;
        }

        next = next->Next;
    }
    return prev;
}

Node* reverseRecursive(Node* &head)
{
    if(head == NULL || head->Next == NULL)     //Base Call
    {
        if(head == NULL)
        {
            cout<<"The list is empty"<<endl;
        }

        return head;
    }

    Node* newHead = reverseRecursive(head->Next);  //Recursive Call
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int findMid(Node* &head)
{
    if(head==NULL)
    {
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

void makeCycle(Node* &head, int pos)
{
    Node* temp = head;
    Node* startNode;
    int count=1;

    while(temp->Next != NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }

        temp = temp->Next;
        count++;
    }

    temp->Next = startNode;
}

bool detectCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;

        if(slow->Next == fast->Next)
        {
            return true;
        }
    }

    return false;
}

void removeCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    do                            //Step-1: Fast == Slow
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    while(slow != fast);

    fast = head;                  //Step 2: Re-initialization of fast

    while(fast->Next != slow->Next)     //Step 3: while fast->Next == slow->Next
    {
        slow = slow->Next;
        fast = fast->Next;
    }

    slow->Next = NULL;            //Step 4: Remove the cycle
}
