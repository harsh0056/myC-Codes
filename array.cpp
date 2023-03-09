#include<bits/stdc++.h>
using namespace std;

//left rotate arr
void rotateLeft(int arr[],int n,int k){
    k=k%n;
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}
//otate right arr
void rotateRight(int arr[],int n,int k){
    k=k%n;
    reverse(arr,arr+n-k);
    reverse(arr+n-k,arr+n);
    reverse(arr,arr+n);
}

//move zeros to end 
void moveZerosToEnd(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0) swap(arr[i],arr[j++]);
    }

}
//leaders in an array problem 
void leadersInArr(int arr[],int n){
    vector<int> ans;
    int currmax=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>currmax) {
            ans.push_back(arr[i]);
            currmax=arr[i];
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
}

//freq of elements in arr
void freqOfElements(int arr[],int n){
    int maxEle=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxEle) maxEle=arr[i];
    }
    vector<int> freq(maxEle+1,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<freq.size() ;i++){
        if(freq[i]!=0) cout<<i<<" "<<freq[i]<<" "<<endl;
    }
    cout<<endl;
}

//maximum diff
void maxDiff(int arr[],int n){
    int currDiff=arr[1]-arr[0];
    int minVal=arr[0];
    for(int i=1;i<n;i++){
        currDiff=max(currDiff,arr[i]-minVal);
        minVal=min(minVal,arr[i]);
    }
    cout<<currDiff<<endl;
}


//trapping rain water solution 
void trappingRainWater(int arr[],int n){
    vector<int> prefixSum(n,0);
    vector<int> suffixSum(n,0);
    prefixSum[0]=arr[0];
    suffixSum[n-1]=arr[n-1];

    for(int i=1;i<n;i++){
        prefixSum[i]=max(arr[i],prefixSum[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suffixSum[i]=max(arr[i],suffixSum[i+1]);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        ans+=min(prefixSum[i],suffixSum[i])-arr[i];
    }
    cout<<"rainwater trapped is : "<<ans<<endl;
}

//max consecutive 1s
void maxConsecutive1s(int arr[],int n){
    int ans=0;
     int count=0;
    for(int i=0;i<n;i++){
       
       if(arr[i]==1) count++;
       else count=0;
       
        ans=max(ans,count);
    }
    cout<<ans<<endl;
}
//maximum even odd subarray 
void maxEvenOddSub(int arr[],int n){
    int count=1;
    int ans=1;
    for(int i=0;i<n;i++){
        
    }
}

//maximum circular subarray 
int kadane(int arr[],int n){
    int maxAns=arr[0];
    int currAns=arr[0];
    for(int i=1;i<n;i++){
        currAns+=arr[i];
        if(currAns<arr[i]){
            currAns=arr[i];
        }
        maxAns=max(maxAns,currAns);

    }
    return maxAns;
}

int maxCircularSubarray(int a[],int n){
        if (n == 1) return a[0]; //only one element 
 
    // Initialize sum variable which store total sum of the array.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
 
    // Initialize every variable with first value of array.
    int curr_max = a[0];
    int max_so_far = a[0];
    int curr_min = a[0];
    int min_so_far = a[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);
 
        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
 
    if (max_so_far <0)
        return max_so_far;
 
    // returning the maximum value
    return max(max_so_far, sum - min_so_far);

}


//repeat and misssing number
void repeatAndMissin(int arr[], int size)
{
    int i;
    cout << "The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
    for(int j=0;j<size;j++) cout<<arr[j]<<" ";

    cout<<endl;
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

int main(){
    int arr[6]={2,3,-10,6,-4,8};
    int arrSum=0;
    for(int i:arr) arrSum+=i;
    cout<<"arr sum is "<<arrSum<<endl;
    cout<<maxCircularSubarray(arr,6)<<endl; 

    int arr2[5]={1,2,3,5,3};
    repeatAndMissin(arr2,5);
}