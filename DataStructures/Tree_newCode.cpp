#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void Preorder(struct Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data;
    Preorder(n->left);
    Preorder(n->right);
}

void Postorder(struct Node* n){
    if(n==NULL){
        return;
    }
    Postorder(n->left);
    Postorder(n->right);
    cout<<n->data;
}

void Inorder(struct Node* n){
    if(n==NULL){
        return;
    }
    Inorder(n->left);
    cout<<n->data;
    Inorder(n->right);
    
}


}

int main() {
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    cout<<"\nPreorder: ";
    Preorder(root);
    cout<<"\nInorder: ";
    Inorder(root);
    cout<<"\nPostorder: ";
    Postorder(root);

    return 0;
}