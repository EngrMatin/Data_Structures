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

void printTreeInOrder(Node *root, int array[], int &index);
int getTreeSize(Node *root);
void heapify(int array[], int n, int current);
void insertNode(int array[], int &n, int key);
void deleteRoot(int array[], int &n);

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
    printTreeInOrder(root, array, size);

    cout<<"Before heapify: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    int nonLeafStart = (n/2)-1;
    for(int i=nonLeafStart; i>=0; i--)
    {
        heapify(array, n, i);
    }

    cout<<"After heapify: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

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

            cout<<"After insert: "<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            deleteRoot(array, n);
        }

        cout<<"After delete: "<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

void heapify(int array[], int n, int current)
{
    int largest = current;
    int leftChild = 2*current + 1;
    int rightChild = 2*current + 2;

    if(leftChild < n && array[leftChild] > array[largest])
    {
        largest = leftChild;
    }

    if(rightChild < n && array[rightChild] > array[largest])
    {
        largest = rightChild;
    }

    if(largest != current)
    {
        swap(array[current], array[largest]);
        heapify(array, n, largest);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertNode(int array[], int &n, int key)
{
    n = n+1;
    array[n-1] = key;

    heapify(array, n, n-1);
}

void deleteRoot(int array[], int &n)
{
    cout<<array[0]<<endl;

    int lastElement = array[n - 1];
    array[0] = lastElement;
    n = n - 1;

    heapify(array, n, 0);
}

void printTreeInOrder(Node *root, int array[], int &index)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left != NULL)
    {
        printTreeInOrder(root->left, array, index);
    }

    array[index] = root->val;
    index++;

    if(root->right != NULL)
    {
        printTreeInOrder(root->right, array, index);
    }
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

/*

0
1 2
3 -1 -1 4
-1 -1     -1 -1


1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1      -1 -1

*/
