#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* right;
Node* left;
Node(int x){
    data=x;
    left=NULL;
    right=NULL;
}
};

// Node* insert(Node* &root,int data){
    
//     if(root==NULL){
//         Node* newnode= new Node(data);
//         root=newnode;
//         return root;
//     }
//     Node* curr= root;
//     while(true){
//         if(data>curr->data){
//             curr->right=insert(curr->right,data);
//         }else if(data<curr->data){
//            curr->left= insert(curr->left,data);
//         }else{
//             curr->right=insert(curr->right,data);
//         }
//     }
// }


Node *insert(Node *root, int x){
    if(root==NULL)
        return new Node(x);
    if(root->data<x)
        root->right=insert(root->right,x);
    else if(root->data>x)
        root->left=insert(root->left,x);
    return root;
} 

void InorderSucc(Node* root){
    if(root==NULL){
        // cout<<"tree is empty"<<endl;
        return ;
    }
    InorderSucc(root->left);
    cout<<root->data<<" ";
    InorderSucc(root->right);

}


int main(){
Node* root=NULL;
insert(root,1);
insert(root,2);
insert(root,3);
insert(root,4);
insert(root,5);
InorderSucc(root);

}