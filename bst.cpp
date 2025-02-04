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
Node*buildtree(int arr[],int n){
    Node*root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
void inorder(Node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(Node*root,int n){
    if(root->data==n){
        return true;
    }if(root==NULL){
    return false;
}
    if(n>root->data){
        return search(root->right,n);
    }
    else{
        return search(root->left,n);
    }
}
Node *inorders(Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node*del(Node*root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data>val){
        root->left=del(root->left,val);
    }
    else if(root->data<val){
        root->right=del(root->right,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            return root->left==NULL? root->right:root->left;
        }
        else{
            Node*is=inorders(root->right);
            root->data=is->data;
            root->right=del(root->right,is->data);
            return root;

        } //hi my name is karan
        
    }
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node*root=buildtree(arr,9);
    inorder(root);
    cout<<endl;
    del(root,5);
    inorder(root); //add my name

    return 0;
}
