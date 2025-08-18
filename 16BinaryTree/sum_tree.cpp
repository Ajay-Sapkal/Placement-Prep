#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> &preorder)
{

    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

int sumTree(Node* root){

    if (root == NULL)
    {
        return 0;
    }

    int left = sumTree(root->left);
    int right = sumTree(root->right);
    root->data += left + right;

    return root->data;
    
}

void preorder_traversal(Node *root)
{

    if (root == NULL)
    {
        // cout<<"-1 ";
        return;
    }

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    preorder_traversal(root);

    
    cout<<endl<< sumTree(root);
    cout<< endl;

    preorder_traversal(root);

    return 0;
}