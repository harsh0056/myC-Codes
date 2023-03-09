#include<bits/stdc++.h>
using namespace std;

int indexOfFirstOcc(int arr[],int n,int x){
    int firstOcc=-1;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(x==arr[mid]){
            firstOcc=mid;
            end=mid-1;
        }else if(x>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return firstOcc;
}

//index of last occurance
int indexOfLastOcc(int arr[],int n,int x){
    int lastOcc=-1;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(x==arr[mid]){
            lastOcc=mid;
            start=mid+1;
        }else if(x>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return lastOcc;
}

//square root

int squareRoot(int n){
    int start=1;
    int end=n;
    int ans=start;
    while(start<=end){
        int mid=start+(end-start)/2;
        int sqroot=mid*mid;
        if(sqroot==n) return mid;
        else if(sqroot<n){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}


//search in a binary sorted rotated array 

int rotatedArr(int arr[],int n,int x){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[start]<arr[mid]){
            //left half is sorted
            if(x>=arr[start] && x<arr[mid]) end=mid-1;
            else start=mid+1;
        }else{
            //right half is sorted
            if(x>arr[mid] && x<=arr[end]) start=mid+1;
            else end=mid-1;
        }
    }
    return -1;
}

//peak element 

int peakElement(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if( (mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid]>arr[mid+1]) ) return mid;
        else if(mid>0 && arr[mid-1]>arr[mid]) end=mid-1;
        else start=mid+1;

    }
    
}




//reapeting element 

void repeatingElement(int arr[],int n){
    int i=0;
    while(i<n){
        if(abs(arr[i])!=i){
            swap(arr[i],arr[i]);
        }
    }
}


int main (){

    int arr[6]={6,9,14,25,1,2};
    cout<<"first occurance is "<<indexOfFirstOcc(arr,6,2)<<endl;
    cout<<"last occurance is "<<indexOfLastOcc(arr,6,2)<<endl;
    cout<<"square root is "<<squareRoot(16)<<endl;
    cout<<"index of number id "<<rotatedArr(arr,6,2)<<endl;
}