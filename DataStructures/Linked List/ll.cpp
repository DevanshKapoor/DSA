#include<iostream>
#include<vector>
using namespace std;
// striver linked list: https://www.youtube.com/watch?v=Nq7ok-OyEpg&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=2
struct Node{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;  
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

int main(){
    Node* y=new Node(5);
    cout<<y->data<<endl;
    vector<int> arr(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    
    Node* head=convertArr2LL(arr);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}