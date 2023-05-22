#include<bits/stdc++.h>
#include "myStackTemplate.h"
using namespace std;

int globalID = 100;

class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id= globalID;
        globalID++;
    }

    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    float getSalary()
    {
        return salary;
    }

    void print()
    {
        cout<<name<< " | "<<id<< " | "<<salary<<endl;
    }
};

int main()
{
    Stack <person> st;
    person a ("Akib Zaman", 10500.50);
    person b ("Sakib Rahman", 20800.80);
    person c ("Arko Ahmed", 30900.90);
    person d ("Ratan Kumar", 40300.35);

    st.push(a);
    st.push(b);
    st.push(c);

    while(!st.empty())
    {
        person printObj;
        printObj = st.pop();
        printObj.print();
    }

    st.push(d);
    cout<<st.size()<<endl;

    person printObj;
    printObj = st.topElement();
    printObj.print();

    return 0;
}
