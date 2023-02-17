#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    Node* left;
    int data;
    Node* right;
    Node(val){
        data=val;
        left =NULL;
        right=NULL;
    }
}
void insert(Node* &root,int val){
    Node* newnode= new Node(val);
    if(root==NULL){
        root =newnode;
        return;
    }
    Node* current=root;
    while (true){
    if(val>=current->data){
        if(current->right==NULL){
            current->right=newnode;
            return;
        }else{
            current=current->right;
        }
    }else{
        if(current->left==NULL){
            current->left=newnode;
            return;
        }else{
            current=current->left;
        }
    }
}

void bfs(Node* root){
    if(root==NULL){
        
    }
    
}

int main(){

}