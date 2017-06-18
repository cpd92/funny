#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*This algorithm is to check a binary tree is a binary search tree (BST) or not*/

struct Node
{
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

Node* CreatNode(int new_val)
{
    Node* n=new Node;
    n->data=new_val;
    
    return n;
}

/*bool isBST(Node* root, Node* l=NULL, Node* r=NULL)        //another implementation
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->data < l->data)
        return false;
 
    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->data > r->data)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}*/

bool isBST(Node* root)
{
    static Node* pre=NULL;
    
    if(root!=NULL)
    {
        if(isBST(root->left)==false)
        {
            return false;
        }
        
        if(pre!=NULL && root->data<=pre->data)
        {
            return false;
        }
        
        pre=root;
        
        return isBST(root->right);
    }
    
    return true;
}

int main()
{
    Node *root=CreatNode(4);
    root->left=CreatNode(2);
    root->right=CreatNode(5);
    root->left->left=CreatNode(1);
    root->left->right=CreatNode(3);
 
    if (isBST(root))
    {
        cout<<"This Tree is BST."<<endl;
    }
    else
    {
        cout<<"This Tree is not BST."<<endl;
    }
        
    return 0;
}
