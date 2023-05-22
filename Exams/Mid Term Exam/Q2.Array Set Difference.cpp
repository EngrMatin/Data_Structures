#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
	cin>>n1;

    int a[n1];
	for(int i=0; i<n1; i++)
    {
        cin>>a[i];
    }

    int n2;
	cin>>n2;

    int b[n2];
	for(int i=0; i<n2; i++)
    {
        cin>>b[i];
    }

    int freq[n1+1]={0};
    for(int j=0; j<n1; j++)
	{
		for(int k=0; k<n2; k++)
		{
			if(a[j]==b[k])
			{
				freq[a[j]]++;
			}
		}
	}

	for(int i=0; i<n1; i++)
    {
        if(freq[a[i]] == 0)
        {
            cout<<a[i]<<" ";
        }
    }

    return 0;
}
