int findMaxK(int* nums, int numsSize) {
    int min,min_limit = -1001;
    do{
        min = 0;
        for(int i=0;i<numsSize;i++)
        {
            if((nums[i]<min)&&(nums[i]>min_limit))
                min = nums[i];
        }
        min_limit = min;

        for(int i=0;i<numsSize;i++)
            nums[i] += min;
        for(int i=0;i<numsSize;i++)
            if((min!=0)&&(nums[i]==0))
                return (-1*min);
        for(int i=0;i<numsSize;i++)
            nums[i] -= min;       
    }while(min!=0);
    return -1;
}