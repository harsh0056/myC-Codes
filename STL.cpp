#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
using namespace std;

int main(){
    vector<int> v={1,2,3,4,65};
    deque<string> d;
    d.push_back("Harsh");
    d.push_back("Swami");
    d.push_front("HI My  Name is");
    priority_queue<int> q;
    list<int> l;
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    cout<<"Elements of List -> ";
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    q.push(59);
    q.push(485);
    q.push(285);
    // for(int i=0;i<q.size();i++){
    //     cout<<q[i]<<" ";
    // }
    cout<<"Size of Queue -> "<<q.size()<<endl;
    cout<<"Element of Vector -> ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"Top Element Of Queue -> "<<q.top()<<endl;
    
}