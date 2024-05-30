int duplicateNumbersXOR(int* nums, int size) {
    int max=1,xor=0;
    for(int i=0;i < size;i++)
        if(nums[i] > max)
            max = nums[i];
    int hash[max+1];
    for(int i=0;i < max+1;i++)
        hash[i]=0;
    for(int i=0;i < size;i++)
        hash[nums[i]]++;
    for(int i=0;i < max+1;i++)
        if(hash[i] == 2)
            xor ^= i;
    return xor;
}