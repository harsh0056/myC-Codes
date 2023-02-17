#include<iostream>
using namespace std;
#define n 1000
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next = NULL;
    }
};

class queue{
    Node* front;
    Node* rear;
    public:
    queue(){
        front =NULL;
        rear=NULL;
    }
    void enqueue(int val){
        Node* newnode= new Node(val);
        if(front==NULL){
            front= newnode;
            rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=newnode;
        return;
    }
    void dequque(){
        if(front==NULL){
            cout<<"Cannot Dequeue More"<<endl;
            return ;
        }
        Node* current=front;
        front=front->next;
        current->next=NULL;
        return;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return -1 ;
        }
        return front->data;
    }
    void List(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return ;
        }
        while(front!=NULL){
            cout<<front->data<<"->";
            front=front->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(3);
    q.dequque();
    cout<<q.peek()<<endl;
    q.List();
}