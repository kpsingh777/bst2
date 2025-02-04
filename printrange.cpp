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
void range(Node*root,int val1,int val2){
    if(root==NULL){
        return;
    }
    if(val1<= root->data && root->data <=val2){
        cout<<root->data<<" ";
        range(root->left,val1,val2);
     range(root->right,val1,val2);
    }
    else if(root->data<val1){
        range(root->right,val1,val2);
    }
    else{
        range(root->left,val1,val2);
    }
     
}
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node*root=buildtree(arr,9);
    cout<<endl;
    range(root,5,12);
    return 0;
    

}
