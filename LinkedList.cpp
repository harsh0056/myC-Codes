#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void insert(Node* &head,int x){
    Node* newnode= new Node(x);
    if(head==NULL){
        head=newnode;
        return;
    }
    Node* temp= head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next =newnode;
    return;
}

void traverse(Node* head){
    while(head){
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<" "<<endl;
}

Node* reverseListIterative(Node* head){
Node* curr= head;
Node* prev=NULL;
Node* next;
while(curr){
     next= curr->next;
    curr->next=prev;
    prev= curr;
    curr=next;

}

return prev;

}

Node* reverseListRecursive(Node* head){
    if(head==NULL || head->next ==NULL) return head;
    Node* newhead= reverseListRecursive(head->next);
    head->next->next = head;
    head->next= NULL;
    return newhead;
}

Node* newNode(int data)
{
    Node* new_node = new Node(data);
    return new_node;
}

Node* addTwoNumber(Node* first,Node* second){

//     Node* temp1=reverseListRecursive(head1);
//     Node* temp2=reverseListRecursive(head2);
//     Node* temp3=NULL;
//     int carry=0;
//     int sum=0;
//     while(temp1 || temp2 ){
//         sum=carry+temp1?temp1->data:0 +temp2?temp2->data:0;
//         if(sum>=10) carry=1;
//         else carry =0;
//         sum=sum%10;
//         insert(temp3,sum);
//         if(temp1) temp1=temp1->next;
//         if(temp2) temp2=temp2->next;
//     }
//     if(carry){
//         insert(temp3,carry);
//     }
//     traverse(temp3);
//     Node* ans=reverseListRecursive(temp3);
//     return ans;
// //     while(temp1){
// //         sum=carry+temp1->data;

// //         temp1=temp1->next;
// //     }
// // while(temp2){
// //         sum=carry+temp1->data;
// //         temp1=temp1->next;
// //     }
  // res is head node of the resultant list
     Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
    first= reverseListRecursive(first);
    second= reverseListRecursive(second);
 
    // while both lists exist
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
          // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = new Node(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest.
        else
            prev->next = temp;
       
        // Set prev for next insertion
        prev = temp;
 
        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = new Node(carry);
    // return head of the resultant list
    return reverseListRecursive(res);

}


Node* reverseInGroupsOfSizeK(Node* head,int k){
    Node* curr= head;
    Node* prev=NULL;
    Node* next=NULL;
    int count=k;
    while(curr && count>0){
        next=curr->next;
        curr->next =prev;
        prev=curr;
        curr=next;
        count--;
    }
    if(next){
        Node* rest_head= reverseInGroupsOfSizeK(next,k);
        head->next =rest_head;
    }
    return prev;

}

bool detectLoop(Node* head){
     Node* slow= head;
        Node* fast= head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
}





int main(){

    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,4);
    insert(head,6);
    insert(head,8);
    traverse(head);
    // Node* head2=NULL;
    // insert(head2,2);
    // insert(head2,7);
    // insert(head2,4);
    // traverse(head2);
    Node*ans=reverseInGroupsOfSizeK(head,3);
    traverse(ans);
    return 0;
    
}