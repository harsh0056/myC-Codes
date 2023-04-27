#include<bits/stdc++.h>
using namespace std;

void intersectionOfArr(int arr1[],int n1,int arr2[],int n2){
unordered_set<int> st;
for(int i=0;i<n1;i++){
    st.insert(arr1[i]);
}
for(int i=0;i<n2;i++){
    if(st.count(arr2[i])) cout<<arr2[i]<<" ";
}
cout<<endl;
}

void subArrWith0Sum(int arr[],int n){
    int sum=0;
    int s=0;
    int e=0;
    unordered_map<int,int> mp;
    mp.insert({0,-1});
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(mp.find(sum)!=mp.end() ){
                s=mp[sum]+1;
                e=i;
        }
        mp[sum]=i;
    }
    cout<<s<<" "<<e<<endl;
}


bool SubArrWithGivenSum(int arr[],int n,int k){
    unordered_set<int> st;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) return true;
        if(st.count(sum-k)) return true;
        st.insert(sum);
    }
    return false;
}


int longestSubarrWithGivenSum(int arr[],int n,int k){
    int sum=0;
    unordered_map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) ans=i+1;
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
        if(mp.find(sum-k)!=mp.end()){
            ans=max(ans,i-mp[sum-k]);
        }
    }
    return ans;
}

void longestSubarrWithEqual1and0(int arr[],int n ){
    for(int i=0;i<n;i++){
        if(arr[i]==0) arr[i]=-1;
    }
    cout<<longestSubarrWithGivenSum(arr,n,0)<<endl;
}



int main(){
int arr1[5]={5,7,9,6,1};
int arr2[6]={5,-5,3,2,1,-6};
int arr3[7]={1,0,1,1,1,0,0};
intersectionOfArr(arr1,5,arr2,6);
subArrWith0Sum(arr2,6);
cout<<SubArrWithGivenSum(arr2,6,-2)<<endl;
cout<<longestSubarrWithGivenSum(arr2,6,2)<<endl;
longestSubarrWithEqual1and0(arr3,7);
}