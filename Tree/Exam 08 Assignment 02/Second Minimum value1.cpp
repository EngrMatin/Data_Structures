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

vector<int> ans;                        // Initialize a vector

void inorderTraversal(Node* root)       // Traversing the tree by using inorder traversal
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        ans.push_back(root->value);
        inorderTraversal(root->right);
    }
}

int findSecondMinimumValue(Node* root)      // Function to find the second minimum element
{
    inorderTraversal(root);

    sort(ans.begin(), ans.end());            // Sorting the array element

    for(int i=0; i<ans.size()-1; i++)        // Traversing and array and checking the second minimum element
    {
        if(ans[i] != ans[i+1])
        {
            return ans[i+1];
        }
    }

    return -1;
}

int main()
{
    Node* root = new Node(2);

    root->left = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int secondMinimumValue = findSecondMinimumValue(root);     // Function call
    cout << secondMinimumValue << endl;

    return 0;
}

//         2
//        / \
//       2   5
//          / \
//         5   7
