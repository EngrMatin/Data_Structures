#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int getTreeSize(Node *root);
void saveTreeInorder(Node *root, int array[], int &index);

int main()
{
    int a;
    cin>>a;

    Node *root = new Node(a);

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int x, y;
        cin>>x>>y;

        Node *n1 = NULL;
        Node *n2 = NULL;

        if(x != -1)
        {
            n1 = new Node(x);
        }

        if(y != -1)
        {
            n2 = new Node(y);
        }

        temp->left = n1;
        temp->right = n2;

        if(n1 != NULL)
        {
            q.push(n1);
        }

        if(n2 != NULL)
        {
            q.push(n2);
        }
    }

    int n = getTreeSize(root);
    int* array = new int[n];

    int size = 0;
    saveTreeInorder(root, array, size);

    priority_queue<int, vector<int>> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(array[i]);
    }

    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int choice;
        cin>>choice;

        if(choice == 1)
        {
            int key;
            cin>>key;
            pq.push(key);
        }
        else if(choice==2)
        {
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }

    return 0;
}

int getTreeSize(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return (getTreeSize(root->left) + getTreeSize(root->right) +1);
    }
}

void saveTreeInorder(Node *root, int array[], int &index)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left != NULL)
    {
        saveTreeInorder(root->left, array, index);
    }

    array[index] = root->val;
    index++;

    if(root->right != NULL)
    {
        saveTreeInorder(root->right, array, index);
    }
}








/*

0
1 2
3 -1 -1 4
-1 -1 -1 -1
4
2
1 10
1 8
2


0
1 2
3 -1 -1 4
-1 -1 -1 -1
4
2
2
2
2

Output:
4
3
2
1



1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1      -1 -1

*/
