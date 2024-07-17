#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

node* insertTree(node* &root, int val){
    //base case
    if(root==NULL){
        root=new node(val);
        return root;
    }
    //right mai insert
    if(root->data<val){
        root->right=insertTree(root->right,val);
    }
    //left mai insert
    else{
         root->left=insertTree(root->left,val);
    }
    return root;
}
void readData(node* &root){
    int val;
    cin>>val;
    while(val!=-1){
        insertTree(root,val);
        cin>>val;
    }
}
void min(node* root){
    node*temp=root;
    while(temp!=NULL){
        temp=temp->left;
    }
    cout<<temp->data;
}

int main(){

   node*root =NULL;
   readData(root);
   return 0;
}