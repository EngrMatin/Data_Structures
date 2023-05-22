#include<bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> v;
    int leftChild(int i)
    {
        return i*2+1;
    }

    int rightChild(int i)
    {
        return i*2+2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    void heapify(int start)
    {
        int leftIndex = leftChild(start);
        int rightIndex = rightChild(start);
        int smallest = start;

        if(leftIndex < v.size() && v[leftIndex] < v[smallest])
        {
            smallest = leftIndex;
        }

        if(rightIndex < v.size() && v[rightIndex] < v[smallest])
        {
            smallest = rightIndex;
        }

        if(smallest != start)
        {
            swap(v[start], v[smallest]);
            heapify(smallest);
        }
    }

public:
    void Push(int val)
    {
        v.push_back(val);
        int insertIndex = v.size()-1;
        while(v[insertIndex] < v[parent(insertIndex)])
        {
            swap(v[insertIndex], v[parent(insertIndex)]);
            insertIndex = parent(insertIndex);
        }
    }

    int Top()
    {
        return v[0];
    }

    void Pop()
    {
        v[0] = v[v.size()-1];
        v.pop_back();
        heapify(0);
    }

    bool Empty()
    {
        return v.size() == 0;
    }
};

int main()
{
    PriorityQueue pq;

    pq.Push(20);
    pq.Push(50);
    pq.Push(40);
    pq.Push(5);
    pq.Push(30);
    pq.Push(15);

    while(!pq.Empty())
    {
        int v = pq.Top();
        pq.Pop();
        cout<<v<<endl;
    }

    return 0;
}
