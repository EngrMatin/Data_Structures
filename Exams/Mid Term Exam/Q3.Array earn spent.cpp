#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
	cin>>t;

    while(t--)
    {
        int d;
        cin>>d;

        int earn[d];
        for(int i=0; i<d; i++)
        {
            cin>>earn[i];
        }

        int spent[d];
        for(int i=0; i<d; i++)
        {
            cin>>spent[i];
        }

        int q;
        cin>>q;

        int query[q];
        for(int i=0; i<q; i++)
        {
            cin>>query[i];
            int earnSum=0, spentSum=0, balance=0;
            for(int j=0; j<=query[i]; j++)
            {
                earnSum += earn[j];
                spentSum += spent[j];

                balance = earnSum - spentSum;
            }
            //cout<<"earnSum= "<<earnSum<<endl<<"spentSum= "<<spentSum<<endl<<"balance= "<<balance<<endl;

            if(balance<0)
            {
                cout<<0;
            }
            else
            {
                cout<<1;
            }
            cout<<endl;
        }
    }

    return 0;
}
