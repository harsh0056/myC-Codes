#include<bits/stdc++.h>
using namespace std;


void snakeTraversal(vector<vector<int>> mat){
    bool change=false;
    for(int i=0;i<mat.size();i++){
        if(!change){
        for(int j=0;j<mat[0].size() ;j++){
            cout<<mat[i][j]<<" ";
        }    
        cout<<endl;
        }else{
            for(int j=mat[0].size()-1;j>=0 ;j--){
                cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        }
        change=!change;
        
    }
}


void boundaryTraversal(vetcor<vector<int>> mat){
    
}


int main(){
vector<vector<int>> mat={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
snakeTraversal(mat);
}