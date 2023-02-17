#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int n){
      for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]) swap(arr[j],arr[i]);
        }
      }
}


void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}


int Lomuto(int arr[],int l,int h){
    int pivot= arr[h];
    int j=l-1;
    for(int i=l;i<h;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[h]);
    return j+1;
}


void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=Lomuto(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}


void heapify(int arr[],int n,int i){
    int largest =i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int arr[],int n){
    for(int i= (n-2)/2;i>=0;i-- ){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    int n=6;
int arr[n]={4,2,8,3,1,5};
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
heapSort(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}