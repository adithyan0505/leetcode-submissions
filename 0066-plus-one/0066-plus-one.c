/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recursive(int* digit, int digitSize) {
    if ((digit[digitSize - 1]) == 9) {
        if ((digitSize - 1) == 0)
            return NULL;
        else {
            digit[digitSize - 1] += 1;
            digit[digitSize - 1] = digit[digitSize - 1] % 10;
            recursive(digit, digitSize - 1);
        }
    } else
        digit[digitSize - 1] += 1;
    return digit;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* arr = (int*)malloc(digitsSize * sizeof(int));
    for(int i=0;i<digitsSize;i++) arr[i] = digits[i];
    int flag = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (arr[i] != 9) {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        (*returnSize) = digitsSize + 1;
        arr = (int*)realloc(arr,(digitsSize+1)*sizeof(int));
        arr[0]=1;
        for(int i=1;i<digitsSize+1;i++) arr[i]=0;
    }
    else
    {
        (*returnSize) = digitsSize;
        recursive(arr, digitsSize);
    }
    return arr;
}