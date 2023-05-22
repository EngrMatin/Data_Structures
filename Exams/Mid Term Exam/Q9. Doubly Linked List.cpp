#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode* Next;
    doublyNode* Prev;

    doublyNode()
    {
        value= NULL;
        Next= NULL;
        Prev= NULL;
    }
};


int main()
{
    doublyNode* head= NULL;
    doublyNode* nodes[101];
    int status[101];

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        int left, right;
        cin>>left>>right;

        doublyNode *nod;
        nod->value = i;
        nod->Prev = left;
        nod->Next = right;
        nodes[i] = nod;
    }

    int now, number=1, before;
    for(int i=1; i<=n; i++)
    {
        if(nodes[i]->Prev == 0)
        {
            now = i;
            before = now;
            status[i] = 1;
            break;
        }
    }

    while(nodes[now]->Next != 0)
    {
        before = now;
        now = nodes[now]->Next;
        number++;
        status[now] = 1;
    }

    while(number < n)
    {
        for(int i=1; i<=n; i++)
        {
            if(nodes[i]->Prev == 0 && status[i] == 0)
            {
                before = now;
                now = i;
                number++;
                status[i] = 1;
                break;
            }
        }

        nodes[now]->Prev = before;
        nodes[before]->Next = now;
        while(nodes[now]->Next != 0 && status[now != 0])
        {
            number++;
            before = now;
            now = nodes[now]->Next;
            status[now]=1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<nodes[i]->Prev<<" "<<nodes[i]->Next<<endl;
    }

    return 0;
}


