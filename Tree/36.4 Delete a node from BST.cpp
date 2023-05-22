#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node *root, int level);
void spacePrint(int level);
void inOrderTraversal(Node *root, string &chk);
void preOrderTraversal(Node *root, string &chk);
void postOrderTraversal(Node *root, string &chk);
int levelOrderTraversal(Node *root, string &chk, int k);
void boundaryTreeTraversal(Node *root);
void printLeaves(Node *root);
void printLeftNonLeaves(Node *root);
void printRightNonLeaves(Node *root);
Node* insertIntoBST(Node* root, int value);
Node* searchInBST(Node* root, int value);
string searchInBST2(Node* root, int value, string &path);
bool isValueExist(Node* root, int value);
Node* deleteFromBST(Node* root, int value);
Node* inOrderSuccessor(Node* root);

int main()
{
    int n;
    cin>>n;

    Node *root = NULL;
    int value;
    for(int i=0; i<n; i++)
    {
        cin>>value;
        root = insertIntoBST(root, value);
    }

    string inOrderResult = "";
    inOrderTraversal(root, inOrderResult);
    cout<<"Inorder Traversal: "<<inOrderResult<<endl;

    int key;
    cin>>key;
//    string searchPath = "";
//    if(searchInBST2(root, key, searchPath) != "empty")
//    {
//        cout<<"Search Path in the BST: "<<searchPath<<endl;
//
//        if(isValueExist(root, key))
//        {
//            cout<<"\nThe value exists in the BST"<<endl;
//        }
//        else
//        {
//            cout<<"\nThe value does not exist in the BST"<<endl;
//        }
//    }

    root = deleteFromBST(root, key);

    inOrderResult = "";
    inOrderTraversal(root, inOrderResult);
    cout<<"Inorder Traversal after deletion: "<<inOrderResult<<endl;

    return 0;
}

void printTree(Node *root, int level)
{
    if (root==NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        cout << root->data <<endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if(root->left != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->left, level+1);
    }

    if(root->right != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->right, level+1);
    }

}

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout <<"   ";
    }
}

void inOrderTraversal(Node *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left, chk);
    chk += (to_string(root->data) + " ");
    inOrderTraversal(root->right, chk);
}

void preOrderTraversal(Node *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    chk += (to_string(root->data) + " ");
    preOrderTraversal(root->left, chk);
    preOrderTraversal(root->right, chk);
}

void postOrderTraversal(Node *root, string &chk)
{
    if(root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left, chk);
    postOrderTraversal(root->right, chk);
    chk += (to_string(root->data) + " ");
}

int levelOrderTraversal(Node *root, string &chk, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int level = 0, max = -9999;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    cout<<"Level Order Traversal: ";
    while(!q.empty())
    {
        Node *chkNode = q.front();
        q.pop();

        if(chkNode != NULL)
        {
            if(level == k)
            {
                if(max < chkNode->data)
                {
                    max = chkNode->data;
                }
            }

            cout<<chkNode->data<<" ";
            chk += (to_string(root->data) + " ");

            if(chkNode->left != NULL)
            {
                q.push(chkNode->left);
            }

            if(chkNode->right != NULL)
            {
                q.push(chkNode->right);
            }
        }
        else
        {
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    cout<<endl;

    return max;
}

void boundaryTreeTraversal(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";

    //LB Non-leaves
    printLeftNonLeaves(root->left);
    //LB leaves
    printLeaves(root->left);
    //RB leaves
    printLeaves(root->right);
    //RB non-leaves;
    printRightNonLeaves(root->right);
}

void printLeaves(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

void printLeftNonLeaves(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->left);
    }
    else if(root->right != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->right);
    }
}

void printRightNonLeaves(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->right != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->right);
    }
    else if(root->left != NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->left);
    }

}

Node* insertIntoBST(Node* root, int value)
{
    Node* newNode = new Node (value);

    if(root==NULL)
    {
        root = newNode;
        return root;
    }

    if(value < root->data)
    {
        root->left = insertIntoBST(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insertIntoBST(root->right, value);
    }

    return root;
}

Node* searchInBST(Node* root, int value)
{
    if(root==NULL)
    {
        return root;
    }

    if(root->data == value)
    {
        cout<<root->data;
        return root;
    }

    if(value < root->data)
    {
        cout<<root->data<<" -> ";
        searchInBST(root->left, value);
    }
    else if(value > root->data)
    {
        cout<<root->data<<" -> ";
        searchInBST(root->right, value);
    }
}

string searchInBST2(Node* root, int value, string &path)
{
    if(root==NULL)
    {
        return "empty";
    }

    if(root->data == value)
    {
        path += (to_string(root->data) + " ");
        return path;
    }

    if(value < root->data)
    {
        path += (to_string(root->data) + " ");
        searchInBST2(root->left, value, path);
    }
    else if(value > root->data)
    {
        path += (to_string(root->data) + " ");
        searchInBST2(root->right, value, path);
    }

    return path;
}

bool isValueExist(Node* root, int value)
{
    bool exist = false;

    if(root==NULL)
    {
        return false;
    }

    if(root->data == value)
    {
        return true;
    }

    if(value < root->data)
    {
        exist = isValueExist(root->left, value);
    }
    else if(value > root->data)
    {
        exist = isValueExist(root->right, value);
    }

    return exist;
}

Node* deleteFromBST(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(key == root->data)
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            root = temp;           //return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            root = temp;            //return temp;
        }
        else
        {
            Node* temp = inOrderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
        }

        return root;
    }
    else if(key < root->data)
    {
        root->left = deleteFromBST(root->left, key);
    }
    else //if(key > root->data)
    {
        root->right = deleteFromBST(root->right, key);
    }

}

Node* inOrderSuccessor(Node* root)             // minimum in the right sub-tree
{
    Node* currentNode = root;

    while(currentNode->left != NULL)           //if left==NULL, return currentNode;
    {
        currentNode = currentNode->left;
    }

    return currentNode;
}

/*

9
11 5 9 43 34 1 2 7 21

*/
