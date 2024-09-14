int longestSubarray(int* nums, int numsSize) {
    int maxi = nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i] > maxi)
            maxi = nums[i];
    }
    int count = 0,prev=-1,curr=0;
    for(int i=0;i<numsSize;i++){
        if((nums[i] == maxi)&&(prev == i-1)){
            curr++;
            prev = i;
        }else if(nums[i] == maxi){
            curr = 1;
            prev = i;
        }else{
            if(curr > count)
                count = curr;
        }
    }
    if(curr > count)
        count = curr;
    return count;
}