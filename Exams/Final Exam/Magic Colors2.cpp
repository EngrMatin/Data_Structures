#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=0; t<test; t++)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        stack<char> st;

        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c);
                continue;
            }

            if(c=='R')
            {
                if(st.empty())
                {
                    break;
                }

                char x = st.top();
                if(x=='R')
                {
                    st.pop();
                }
                else if(x=='G')
                {
                    st.pop();
                    st.push('Y');
                }
                else if(x=='B')
                {
                    st.pop();
                    st.push('P');
                }
                else
                {
                    st.push(c);
                }
            }
            else if(c=='G')
            {
                if(st.empty())
                {
                    break;
                }

                char x = st.top();
                if(x=='G')
                {
                    st.pop();
                }
                else if(x=='R')
                {
                    st.pop();
                    st.push('Y');
                }
                else if(x=='B')
                {
                    st.pop();
                    st.push('C');
                }
                else
                {
                    st.push(c);
                }
            }
            else if(c=='B')
            {
                if(st.empty())
                {
                    break;
                }

                char x = st.top();
                if(x=='B')
                {
                    st.pop();
                }
                else if(x=='R')
                {
                    st.pop();
                    st.push('P');
                }
                else if(x=='G')
                {
                    st.pop();
                    st.push('C');
                }
                else
                {
                    st.push(c);
                }
            }
        }

        stack<char> st2;
        while(!st.empty())
        {
            char p = st.top();
            st.pop();

            st2.push(p);
            if(st.empty())
            {
                break;
            }

            while(!st2.empty())
            {
                if(st.top()==st2.top())
                {
                    st.pop();
                    st2.pop();
                }
                else if(st.top()!=st2.top() || st2.empty()==true)
                {
                    break;
                }
            }
        }

        string ans = "";
        while(!st2.empty())
        {
            ans += st2.top();
            st2.pop();
        }

        cout<<ans<<endl;
    }

    return 0;
}

/*

1
18
RBGRGBBRGBGRGRBGBR
output: PYC



*/
