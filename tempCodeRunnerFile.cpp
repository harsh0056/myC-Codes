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