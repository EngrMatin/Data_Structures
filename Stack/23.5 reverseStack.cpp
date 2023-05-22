
#include<bits/stdc++.h>
#include "myStackTemplate.h"
using namespace std;

void insertAtBottom(Stack <int> &chk, int chkItem)
{
    if(chk.empty())
    {
        chk.push(chkItem);
        return;
    }

    int topItem = chk.topElement();
    chk.pop();
    insertAtBottom(chk, chkItem);

    chk.push(topItem);
}

void reverseStack(Stack<int> &chk)
{
    if(chk.empty())
    {
        return;
    }

    int topItem = chk.topElement();
    chk.pop();
    reverseStack(chk);
    insertAtBottom(chk, topItem);
}

int main()
{
    Stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while(!st.empty())
    {
        cout<<st.pop()<<endl;
    }

    return 0;
}

