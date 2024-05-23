void rotate(int* nums, int numsSize, int k) {
    int i = 0;
    if ((numsSize - k) < 0)
        k = k % numsSize;
    while (i < (numsSize - k - 1 - i)) {
        swap(&nums[i], &nums[numsSize - k - 1 - i]);
        i++;
    }
    i = numsSize - k;
    while (i < (numsSize - 1 - i + numsSize - k)) {
        swap(&nums[i], &nums[numsSize - 1 - i + numsSize - k]);
        i++;
    }
    i = 0;
    while (i < (numsSize - 1 - i)) {
        swap(&nums[i], &nums[numsSize - 1 - i]);
        i++;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}