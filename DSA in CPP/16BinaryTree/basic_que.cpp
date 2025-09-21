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

int height(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int left_h = height(root->left);
    int right_h = height(root->right);

    return max(left_h, right_h) + 1;
}

int count(Node* root){
    if(root == NULL) return 0;

    int lc = count(root->left);
    int rc = count(root->right);

    return (lc+rc+1);

}

int sum(Node* root){
    if(root == NULL) return 0;
    
    int l_sum = sum(root->left);
    int r_sum = sum(root->right);

    return (l_sum + r_sum + root->data);
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    cout << height(root) << endl;
    cout << count(root) << endl;
    cout << sum(root) << endl;
    return 0;
}