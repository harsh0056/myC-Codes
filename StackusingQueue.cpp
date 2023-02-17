#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;
    int top;
    public:
    stack(){
        top=-1;
    }
    void push(int val){
        q1.push(val);
        top++;

    }
    int pop(){
        if(q2.empty()){
            while(!q1.empty()){
                q2.push(q1.back());
                q1.pop();
            }
        }
        int poppped= q2.front();
        q2.pop();
        return poppped;
        
    }
};

int main(){
    stack st;
    st.push(5);
    st.push(2);
    st.push(9);
    st.push(4);
    cout<<st.pop()<<" "<<st.pop()<<endl;
    cout<<st.pop()<<endl;
}