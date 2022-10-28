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



void Sort012(int arr[],int n){
    //sort an array of 0s, 1s and 2s

    // while condition would be mid<=end
    int start=0;
    int mid=0;
    int end=n-1;
    while(mid<=end && start<end){
        if(arr[mid]==0){
                swap(arr[mid++],arr[start++]);
            }else if(arr[mid]==1){
                start++;
            }else{
                swap(arr[mid],arr[end--]); // here we dont increase end because we need to keep checking mid whenever we swap
            }
    }
}

vector<int> LeadersInArray(int arr[],int n){
    //   Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
      
      vector <int> ans;
        stack<int> st;
        st.push(arr[n-1]);
        ans.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=st.top()){
                ans.push_back(arr[i]);
                st.push(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end() );
        return ans;


        //This question can be done without using stack

    vector <int> ans;
        
        int currLdr=arr[n-1];
        ans.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=currLdr){
                ans.push_back(arr[i]);
                currLdr=arr[i];
            }
        }
        reverse(ans.begin(),ans.end() );
        return ans;

}


int equilibriumPoint(long long a[],int n){

// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

    long long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        long long currSum=0,remSum=sum;
        for(int i=0;i<n;i++){
            remSum=remSum-a[i];
            if(remSum==currSum) return i+1;
            currSum+=a[i];
        }
        if(remSum==currSum) return n;
        return -1;
}


int maxLenOfSubArray(vector<int>&arr, int n)
    {   

        // Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

        // Your code here
        unordered_map<int,int> mp;
        int len=0;
        long long currSum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(mp.find(currSum)!=mp.end()){
                len=max(len,i-mp[currSum]);
            }else{
            mp[currSum]=i;
            }
        }
        return len;
    }


int main(){
    
    
    return 0;

}