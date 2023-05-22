#include<bits/stdc++.h>
#include "myStack.h"
using namespace std;

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.empty())
    {
        cout<<st.pop()<<endl;;
    }

    st.push(4);

    cout<<st.size()<<endl;

    if(!st.empty())
    {
        cout<<st.topElement()<<endl;
    }





    return 0;
}

