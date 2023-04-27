#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    Node* right;
    Node(int val){
        data=val;
        left =NULL;
        right=NULL;
    }
};
void insert(Node* &root,int val){
    Node* newnode= new Node(val);
    if(root==NULL){
        root =newnode;
        return;
    }
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        for(int i=0;i<q.size() ;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            else{
                curr->left=newnode;
                return ;
            } 
            if(curr->right){
                q.push(curr->right);
            }else{
                curr->right=newnode;
                return ;
            }
        }
    }
   
}

void inorderTraversal(Node* root){
    if(root==NULL) return ;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}


void preorderTraversal(Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    
    preorderTraversal(root->right);
}

int heightOfTree(Node* root){
    if(root==NULL) return 0;
    return 1+max(heightOfTree(root->left),heightOfTree(root->right));
}

void printNodesAtKDistance(Node* root,int k){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        k--;
        for(int i=0;i<q.size() ;i++){
            Node* curr=q.front();
            q.pop();
            if(i==k) cout<<curr->data;
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);

        }
        cout<<endl;
    }
}

void maxInTreeHelper(Node* root,int &maxno){
    if(root==NULL) return ;    
    maxno=max(root->data,maxno);
    maxInTreeHelper(root->left,maxno);
    maxInTreeHelper(root->right,maxno);
}

int maxInTree(Node* root){
    int maxno=INT_MIN;
    maxInTreeHelper(root,maxno);
    return maxno;
}


void  IterativeInorder(Node* root){
    stack<Node* >st;
    Node* curr= root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
            
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}


bool childrenSumProperty(Node* root){
    if(root==NULL) return true;
    if(!root->left && !root->right) return true;
    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    return (sum==root->data && childrenSumProperty(root->left) && childrenSumProperty(root->right)); 
}



int main(){
    
Node* root=NULL;
insert(root,5);
insert(root,2);
insert(root,3);
insert(root,1);
insert(root,1);
insert(root,2);
insert(root,2);
inorderTraversal(root);
cout<<endl;
cout<<heightOfTree(root)<<endl;
printNodesAtKDistance(root,1);
cout<<maxInTree(root)<<endl;
IterativeInorder(root);
cout<<childrenSumProperty(root)<<endl;
}