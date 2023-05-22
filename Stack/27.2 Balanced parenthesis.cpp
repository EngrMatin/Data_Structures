#include<bits/stdc++.h>
#include"MyStackTemplate.h"

using namespace std;

bool balancedParenthesis(string s)
{
    int n = s.size();
    Stack <char> st;
    bool isBalanced = true;

    if(s[0]== ')' || s[0]== '}' || s[0]== ']')
    {
        return false;
    }

    for(int i=0; i<n; i++)
    {
        if(s[i]== '(' || s[i]== '{' || s[i]== '[')
        {
            st.push(s[i]);
        }
        else if(s[i]== ')')
        {
            if(st.topElement()=='(')
            {
                st.pop();
            }
            else
            {
                isBalanced = false;
                break;
            }
        }
        else if(s[i]== '}')
        {
            if(st.topElement()=='{')
            {
                st.pop();
            }
            else
            {
                isBalanced = false;
                break;
            }
        }
        else if(s[i]== ']')
        {
            if(st.topElement()=='[')
            {
                st.pop();
            }
            else
            {
                isBalanced = false;
                break;
            }
        }
    }

    if(!st.empty())
    {
        isBalanced = false;
    }

    return isBalanced;
}

int main()
{
    string chk;
    cin>>chk;

    if(balancedParenthesis(chk))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    cout<<endl;

    return 0;
}
