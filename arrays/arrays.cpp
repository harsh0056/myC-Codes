#include<bits/stdc++.h>
using namespace std;


int missingNumberFrom1ToN(vector<int> arr,int n){
    //Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

//Writing the most optimal approach only which i think is cyclic sort one

//Other approaches include hashing , summation of Numbers , bit operators 

  int i=0;
        while(i<n){
            if(arr[i]<n && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) return i+1;
        }


        //AnoTher Approach is to mark all the numbers Negative


        int i=0;
        for(int i=0;i<n;i++){
            if(abs(arr[i])-1==n) continue; 
            int currIndx=abs(arr[i])-1;
            arr[i]=arr[currIndx]*-1; //this way we mark all numbers as -ve only once
        }

        int ans=n+1;
        for(int i=0;i<n;i++){
            if(arr[i]>0) ans=i+1;
        }
        return ans;
}


int main(){
    
    
    return 0;

}