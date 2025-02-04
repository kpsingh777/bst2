#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node*insert(Node*root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
Node*buildfromsorted(int arr[],int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node*curr=new Node(arr[mid]);
    curr->left=buildfromsorted(arr,st,mid-1);
    curr->right=buildfromsorted(arr,mid+1,end);
    return curr;
}
Node *inorders(Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[7]={3,4,5,6,7,8,9};
    Node*root=buildfromsorted(arr,0,7);
    preorder(root); //hi
    return 0;
}