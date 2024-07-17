//binary serach tree
#include<iostream>
using namespace std;
//creating node
class node{
public:
    int data;
    node*left;
    node*right;
    
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


node* insertBST(node* root, int val){
    if(root==NULL){
        root=new node(val);
        }
    
    if(val<root->data){
        root->left=insertBST(root->left, val);
    }
    else{
        root->right=insertBST(root->right, val);
    }

    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    
    while(data!=-1){
        root=insertBST(root,data);
        cin>>data;
    }
    
}


node* minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node* maxVal(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}



void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


bool rsearchBST(node* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(x>root->data){
        return rsearchBST(root->right, x);
        
    }
   else{
        return rsearchBST(root->left,x);
    }
}

bool isearchBST(node* root, int x){
    node* temp=root;
    while(temp!=NULL){
        if(temp->data>x){
            temp=temp->left;
        }
        if(temp->data<x){
            temp=temp->right;
        }
        else{
            //temp->data==x
            return true;
        }
    }
    return false;
}

node* deletion(node*root, int key){
    //base case
    if(root==NULL){
        return root;
    }
    
    if(root->data==key){
        //0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left
        if(root->left != NULL && root->right == NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        //right
        if(root->left == NULL && root->right != NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        else{//(root->left != NULL && root->right != NULL)
            int minval=minVal(root->right)->data;
            root->data=minval;
            root->right=deletion(root->right,minval);
            return root;
        }
    }
    else if (root->data>key){
        root->left=deletion(root->left,key);
        return root;
    }
    else{
        root->right=deletion(root->right,key);
        return root;
    }
}//theek hai bilkul bhai


int main(){
    node* root =NULL;
    cout<<"ENTER BST"<<endl;
    takeinput(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<rsearchBST(root,5)<<endl;
        
    cout<<isearchBST(root,25)<<endl;
    cout<<"minimnum = "<<minVal(root)->data<<endl;
    cout<<"maximum = "<<maxVal(root)->data<<endl;
    return 0;
}

