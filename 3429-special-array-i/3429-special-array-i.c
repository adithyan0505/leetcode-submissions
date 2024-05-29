bool isArraySpecial(int* nums, int size) {
    if(size!=1)
    {
        for(int i = 1;i < size;i++)
        {
            if(((nums[i-1]%2==0)&&(nums[i]%2==0))||((nums[i-1]%2==1)&&(nums[i]%2==1)))
                return false;
        }
        return true;
    }
    else
        return true;
}