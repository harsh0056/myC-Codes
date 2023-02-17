function largestsum(arr){
    var max=arr[0];
    for(var i=0;i<arr.length;i++){
        if(arr[i]>max){
            max=arr[i];
        }

    }
    console.log(max);
    return max;
}
largestsum([4,5,7,4,3,96])