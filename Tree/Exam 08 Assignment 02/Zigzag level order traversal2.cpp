#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(string str)                 // Function to Build Tree
{
    if(str.length() == 0 || str[0] == 'N')        // Corner Case
            return NULL;

    vector<string> ip;           // Creating vector of strings from input String after splitting by space

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));       // Create the root of the tree

    queue<Node*> queue;
    queue.push(root);                        // Push the root to the queue

    int i = 1;                               // Starting from the second element
    while(!queue.empty() && i < ip.size())
    {
        Node* currNode = queue.front();      // Get the front of the queue
        queue.pop();                         // Remove the front of the queue

        string currVal = ip[i];              // Get the current node's value from the string

        if(currVal != "N")                   // If the left child is not null
        {
            currNode->left = new Node(stoi(currVal));     // Create the left child for the current node

            queue.push(currNode->left);                   // Push it to the queue
        }

        i++;                           // For the right child
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N")             // If the right child is not null
        {
            currNode->right = new Node(stoi(currVal));     // Create the right child for the current node

            queue.push(currNode->right);                   // Push it to the queue
        }
        i++;
    }

    return root;
}


int treeHeight(Node *root)          // Function to calculate height of tree
{
    if(!root) return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int> &ans)
{
    if(height <= 1)       // Height = 1 means the tree now has only one node
    {
        if(root) ans.push_back(root->value);
    }
    else                // When Height > 1
    {
        if(lor){
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
        }
        else{
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
        }
    }
}

vector <int> zigZagTraversal(Node* root)    // Function to traverse tree in zig zag order
{
    vector<int> ans;
    bool leftOrRight = true;
    int height = treeHeight(root);
    for(int i = 1; i <= height; i++)
    {
        zigZagTraversalRecursion(root, i, leftOrRight, ans);
        leftOrRight = !leftOrRight;
    }
    return ans;
}


int main()
{
    string s = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
    Node* root = buildTree(s);
    vector <int> res = zigZagTraversal(root);

    cout<<"ZigZag traversal of binary tree is:"<<endl;
    for (int i = 0; i < res.size (); i++)
    {
        cout << res[i] << " ";
    }
    cout<<endl;
    return 0;
}

      // Tree:
    //          1
    //        /   \
    //       /     \
    //      /       \
    //     2          3
    //   /   \       /  \
    //  4     5     6     7
    // / \   /  \  / \   /  \
    //8  9  10 11 12 13 14  15

