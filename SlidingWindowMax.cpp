#include<iostream>
#include<deque>
using namespace std;

int main(){
    int x=0;
    int y=x+2;
    int arr[8]={1,3,-1,-3,5,3,6,7};
    while(y!=8){
        int max=arr[x];
        for(int i=x;i<=y;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        cout<<max<<endl;
        x++;
        y++;
    }
}