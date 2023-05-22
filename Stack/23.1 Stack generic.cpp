#include<bits/stdc++.h>
#include "myStackTemplate.h"
using namespace std;

int main()
{
    Stack <string> st;

    st.push("Akib Zaman");
    st.push("Ratan Kumar");
    st.push("Arko Ahmed");

    while(!st.empty())
    {
        cout<<st.pop()<<endl;;
    }

    st.push("Sakib Rahman");

    cout<<st.size()<<endl;

    if(!st.empty())
    {
        cout<<st.topElement()<<endl;
    }


    return 0;
}

