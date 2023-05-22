#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

void rootToLeafPaths(Node* node, vector<int> &path, string s, int &count)
{
    if (node == NULL)
    {
        return;
    }

    path.push_back(node->val);

    if (node->left == NULL && node->right == NULL)
    {
        vector<char> text;
        for(int i=0; i<path.size(); i++)
        {
            text.push_back(s[path[i]]);
        }

        bool isPalindrome = true;
        int x=0;
        int y = text.size()-1;

        while(y>1)
        {
            if(text[x++] != text[y--])
            {
                isPalindrome = false;
            }
        }

        if(isPalindrome)
        {
            count ++;
        }
    }

    rootToLeafPaths(node->left, path, s, count);
    rootToLeafPaths(node->right, path, s, count);

    path.pop_back();
}

void rootToLeafPaths(Node* node, string s, int &count)
{
    vector<int> path;

    rootToLeafPaths(node, path, s, count);
}

int main()
{
    string s;
    cin>>s;

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

    int count=0;
    rootToLeafPaths(root, s, count);
    cout<<count<<endl;

    return 0;
}


/*

ABCAA
0
1 2
3 -1 -1 4
-1 -1 -1 -1

Output:
0 1 3
0 2 4

ABDAD
0
1 2
3 -1 -1 4
-1 -1 -1 -1

Output:
0 1 3
0 2 4



              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
               /     \
              8       9

ABCDBBDEBB
1
2 3
4 5 6 7
-1 -1 -1 -1 8 -1 -1 9
-1 -1 -1 -1

Output:
1 2 4
1 2 5
1 3 6 8
1 3 7 9
*/
