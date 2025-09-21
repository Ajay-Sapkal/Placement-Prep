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

void inorder(Node* root){
    Node* curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node* ip = curr->left;
            while (ip->right != NULL && ip->right != curr)
            {
                ip = ip->right;
            }
            if (ip->right == NULL)
            {
                ip->right = curr;
                curr = curr->left;
            }
            else
            {
                ip->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
            
            
        }
        
        
    }
    
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    inorder(root);
    cout << endl;
    
    return 0;
}