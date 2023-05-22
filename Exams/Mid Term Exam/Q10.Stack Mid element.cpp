#include<bits/stdc++.h>
#include "MATIN_STACK.h"
using namespace std;

int main()
{
    Stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.empty())
    {
        cout<<"st.pop(): ";
        cout<<st.pop()<<endl;
    }

    st.push(4);
    st.push(5);
    st.push(6);
    //st.push(7);

    cout<<"st.size(): ";
    cout<<st.size()<<endl;

    if(!st.empty())
    {
        cout<<"st.topElement(): ";
        cout<<st.topElement()<<endl;

        cout<<"st.midElement(): ";
        cout<<st.midElement()<<endl;
    }

    return 0;
}

