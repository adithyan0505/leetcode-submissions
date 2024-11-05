int helper(int* arr,int left,int right,int target){
    if(left <= right){
        int mid = (right - left)/2 + left;
        if(arr[mid]==target)
            return mid;
        if(arr[mid] >= arr[left]){
            if((arr[mid] > target) && (arr[left] <= target))
                return helper(arr,left,mid-1,target);
            return helper(arr,mid+1,right,target);
        }else{
            if((arr[mid] < target) && (arr[right] >= target))
                return helper(arr,mid+1,right,target);
            return helper(arr,left,mid-1,target);
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    return helper(nums,0,numsSize-1,target);
}