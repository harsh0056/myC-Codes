#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

class queue{
    public:
    int* q;
    int front;
    int rear;
    queue(){
        q=new int[SIZE];
        front=-1;
        rear=-1;
    }
    void enqueue(int val){
        if(front==-1){
            front++;    
        }
        rear++;
        q[rear]=val;
 }
 void dequeue(){
     if(front>rear){
         cout<<"Cannot Dequeue Asshole";
         return;
     }
     front++;
 }
 int peek(){
     return q[front];
 }
 bool isEmpty(){
     if(front==-1){
         return true;
     }else{
         return false;
     }
 }
 void list(){
     if(rear==-1){
         cout<<"queue is Empty"<<endl;
         return;
     }
     for(int i=0;i<=rear;i++){
         cout<<q[i]<<" ";
     }
     cout<<endl;
 }
};
 
 

int main(){
    queue q;
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(7);
    q.enqueue(2);
    cout<<q.peek()<<endl;
    q.list();
    cout<<q.front<<" "<<q.rear<<endl;


}