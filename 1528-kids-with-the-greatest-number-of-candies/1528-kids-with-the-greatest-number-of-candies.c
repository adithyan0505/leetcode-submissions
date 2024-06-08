/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extra,
                      int* returnSize) {
    *returnSize = candiesSize;
    bool* array = (bool*)malloc(candiesSize * sizeof(bool));
    int max = 0;
    for (int i = 0; i < candiesSize; i++)
        if (max < candies[i])
            max = candies[i];
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extra >= max)
        {
            array[i] = true;
            continue;
        }
        array[i] = false;
    }
    return array;
}