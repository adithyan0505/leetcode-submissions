/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int start = 0, end = numbersSize-1;
    while(start <= end)
    {
        if(numbers[start]+numbers[end]==target)
            break;
        else if(numbers[start]+numbers[end]<target)
            start++;
        else
            end--;
    }
    int* ret = (int*)malloc(2*sizeof(int));
    ret[0] = start+1;
    ret[1] = end+1;
    *returnSize = 2;
    return ret;
}