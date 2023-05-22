#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;

int main()
{
    priority_queue<int, vector<int>> pq; //The larger the value, the higher the priority
    pq.push(1);
    pq.push(6);
    pq.push(2);

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<endl<<endl;

    priority_queue<int, vector<int>, greater<int>> pq2; //The smaller the value, the higher the priority
    pq2.push(1);
    pq2.push(6);
    pq2.push(2);

    while(!pq2.empty())
    {
        cout<<pq2.top()<<endl;
        pq2.pop();
    }
    cout<<endl<<endl;

    priority_queue<PAIR, vector<PAIR>> pq3; // Priority according to first element. The larger the value, the higher the priority
    pq3.push(make_pair(1, 9));
    pq3.push(make_pair(6, 3));
    pq3.push(make_pair(4, 2));
    pq3.push(make_pair(2, 1));

    while(!pq3.empty())
    {
        cout<<pq3.top().first<<" | "<<pq3.top().second<<endl;
        pq3.pop();
    }
    cout<<endl<<endl;

    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq4; // Priority according to first element. The smaller the value, the higher the priority
    pq4.push(make_pair(1, 9));
    pq4.push(make_pair(6, 3));
    pq4.push(make_pair(4, 2));
    pq4.push(make_pair(2, 1));

    while(!pq4.empty())
    {
        cout<<pq4.top().first<<" | "<<pq4.top().second<<endl;
        pq4.pop();
    }
    cout<<endl<<endl;

    return 0;
}
