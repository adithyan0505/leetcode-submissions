int searchInsert(int* nums, int size, int target) {
    int mid, low = 0, high = size - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (target > nums[mid])
        return mid + 1;
    else
        return mid;
}