int missingNumber(int* nums, int size) {
    int hash[size+1];
    for (int i = 0; i < size+1; i++)
        hash[i] = 0;
    for (int i = 0; i < size; i++)
        hash[nums[i]]++;
    int i;
    for (i = 0; i < size+1; i++)
        if (hash[i] == 0)
            break;
    return i;
}