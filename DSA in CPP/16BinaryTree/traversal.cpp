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

Node *build_tree(vector<int> &preorder)
{

    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = build_tree(preorder);
    root->right = build_tree(preorder);

    return root;
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

void inorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void levelOrder_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if (q.empty())
            {
                break;
            }
            else{
                cout<<endl;
                q.push(NULL);
                continue;
            }
            
        }

        cout<< curr->data << " ";

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = build_tree(preorder);

    preorder_traversal(root);
    cout << endl;

    inorder_traversal(root);
    cout << endl;

    postorder_traversal(root);
    cout << endl;

    levelOrder_traversal(root);
    cout << endl;

    return 0;
}