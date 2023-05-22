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
void heapify(int array[], int &n, int current);
void deleteRoot(int array[], int &n);
void heapifyBottomUp(int array[], int &n, int current);
void insertNode(int array[], int &n, int key);

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

    int nonLeafStart = (n/2)-1;
    for(int i=nonLeafStart; i>=0; i--)
    {
        heapify(array, n, i);
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
            insertNode(array, n, key);
        }
        else if(choice==2)
        {
            deleteRoot(array, n);
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

void heapify(int array[], int &n, int current)
{
    int largest = current;
    int left = 2*current+1;
    int right = 2*current+2;

    if(left<n && array[left]>array[largest])
    {
        largest = left;
    }

    if(right<n && array[right]>array[largest])
    {
        largest = right;
    }

    if(largest != current)
    {
        swap(array[current], array[largest]);

        heapify(array, n, largest);
    }
}

void deleteRoot(int array[], int &n)
{
    cout<<array[0]<<endl;

    int lastElement = array[n-1];
    array[0] = lastElement;
    n = n-1;

    heapify(array, n, 0);
}

void heapifyBottomUp(int array[], int &n, int current)
{
    int parent = (current-1)/2;

    if(array[parent] > 0)
    {
        if(array[current] > array[parent])
        {
            swap(array[current], array[parent]);

            heapifyBottomUp(array, n, parent);
        }
    }
}

void insertNode(int array[], int &n, int key)
{
    n = n+1;
    array[n-1] = key;

    heapifyBottomUp(array, n, n-1);
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
