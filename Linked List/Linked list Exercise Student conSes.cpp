#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    string mobileNo;
    string section;
    float attendance;
    Student *Next;

    Student(int roll, string name1, string mobile, string sec, float att)
    {
        rollNo = roll;
        name = name1;
        section = sec;
        attendance = att;
        Next = NULL;
    }
};

void insert(Student* &head, int rollNo, string name, string mobileNo, string section, float attendance);
void display(Student *node);

int main()
{
    Student *head;
    int option;
    int rollNo;
    string name;
    string mobileNo;
    string section;
    float attendance;

    cout<<"Option 1: Insert in the list"<<endl
        <<"Option 2: Display list"<<endl;
    cout<<"\nEnter your Choice: ";

    cin>>option;

    switch(option)
    {
    case 1:
        cout<<"Enter Roll No: "<<endl;
        cin>>rollNo;
        cout<<"Enter Name: "<<endl;
        cin>>name;
        cout<<"Enter Mobile No: "<<endl;
        cin>>mobileNo;
        cout<<"Enter Section: "<<endl;
        cin>>section;
        cout<<"Enter Attendance: "<<endl;
        cin>>attendance;

        insert(head, rollNo, name, mobileNo, section, attendance);
        break;

    case 2:
        display(head);
        break;

    default:
        break;
    }

    return 0;
}

void insert(Student* &head, int rollNo, string name, string mobileNo, string section, float attendance)
{
    Student *newNode = new Student(rollNo, name, mobileNo, section, attendance);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Student *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

void display(Student *node)
{
    while(node != NULL)
    {
        cout<<"Roll No: "<<node->rollNo<<endl;
        cout<<"Name: "<<node->name<<endl;
        cout<<"Mobile No: "<<node->mobileNo<<endl;
        cout<<"Section: "<<node->section<<endl;
        cout<<"Attendande: "<<node->attendance<<endl;

        node = node->Next;

        cout<<endl;
    }
}
