int singleNumber(int* nums, int size) {
    int unique = 0;
    for (int i = 0; i < size; i++)
        unique ^= nums[i];
    return unique;
}