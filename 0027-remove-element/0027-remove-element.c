int removeElement(int* nums, int size, int val) {
    int p1=0,p2=size-1,temp;
    while(p1 <= p2)
    {
        if(nums[p1] == val)
        {
            temp = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = temp;
            p2--;
        }
        else 
            p1++;
    }
    return p2+1;
}