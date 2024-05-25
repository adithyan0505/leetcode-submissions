int findMaxK(int* nums, int numsSize) {
    int min,max,max_limit = 1001;
    do
    {
        min = 0; max = 0;
        for (int i = 0; i < numsSize; i++)
            if ((nums[i] > max)&&(nums[i] < max_limit))
                max = nums[i];
        for (int i = 0; i < numsSize; i++)
            if ((nums[i] < min)&&(nums[i] + max == 0))
                min = nums[i];
        max_limit = max; 
    }while(min + max != 0);
    if(min==max)
        return -1;
    else
        return max;
}