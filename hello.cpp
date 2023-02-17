#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int largestnum(int arr[],int n){
    int lar=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>lar){
            lar =arr[i];
            }
    }
    int *ans;
    return lar;
}

int main(){
    int arr[5]={4,8,6,1,3};
    int ans=largestnum(arr,5);
    cout<<"The Largest Number is "<<ans<<endl;
}

//middle element in a linked list
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node {
        public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
    };
    void insert(node* &head,int val){
       node* newnode = new node(val);
       if(head==NULL){
           head = newnode;
           return ;
       } 
       else{
           node* current= head;
           while (current->next!=NULL){
               
               current=current->next;

           } 
           current->next= newnode;
           return ;
       }
    }
    void display(node* head){
        if(head==NULL){
            cout<<"NOthing to display"<<endl;
            return ;        
        }
        node* current=head;
        while (current!=NULL){
            cout<<current->data<<"->";
            current=current->next;
        }
        cout<<"NULL"<<endl;
    }
void  middleElement(node* head){
    node* fast= head;
    node* slow= head;     
    while (fast!=NULL && fast->next!=NULL){
       slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}

void bubbleSort(int arr[],int n){
    int count=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            bool noswaps=true;
            if(arr[j]>arr[j+1]){
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                noswaps=false;
                count++;
            }
          if(noswaps)break;  
        }

    }
    cout<<count<<endl;
}

void selectionSort(int arr[],int n){
    int index;
    int count=0;
    for(int i=0;i<n;i++){
        int min=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        //swap
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
        count++;
    }
    cout<<count<<endl;
}

void sortList(node* head){

}

int main(){
    node* head =NULL;
    insert(head,5);
    insert(head,6);
    insert(head,2);
    insert(head,9);
    insert(head,2);
    insert(head,7);
    display(head);
    middleElement(head);
    int arr[6]={7,5,4,1,6,9};
    bubbleSort(arr,6);
    // selectionSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}