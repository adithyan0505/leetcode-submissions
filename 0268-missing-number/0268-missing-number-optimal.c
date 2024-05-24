int missingNumber(int* nums, int size) {
    int sum = 0;
    for(int i=0;i<size;i++)
        sum += nums[i];
    return ((size*(size+1))/2 - sum);
}