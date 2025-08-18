#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Inorder(Node* root){
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
    
}

Node* insert(Node* root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

Node* build_BST(vector<int>& vec){
    Node* root = NULL;

    for(int val: vec){
        root = insert(root, val);
    }
    return root;
}

bool search(Node* root, int val){
    if (root == NULL)
    {
        return false;
    }

    if (root->data == val)
    {
        return true;
    }

    if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }

    
}

Node* inorder_successor(Node* root){
    if (root->left == NULL)
    {
        return root;
    }
    return inorder_successor(root->left);
    
}

Node* delete_node(Node* root, int val){
    if (root == NULL)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root->left = delete_node(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete_node(root->right, val);
    }
    else
    {

        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node* IS = inorder_successor(root->right);
            root->data = IS->data;
            root->right = delete_node(root->right, IS->data);
        }

    }

    return root;
}
int main()
{
    vector<int> vec = {3, 2, 1, 5, 6, 4};

    Node* root = build_BST(vec);
    Inorder(root);
    cout << endl;

    // cout << search(root, 8) << endl;

    delete_node(root, 5);
    Inorder(root);
    cout << endl;

    return 0;
}