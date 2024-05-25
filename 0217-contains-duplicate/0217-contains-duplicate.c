void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int size, int i) {
    int larg = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && arr[left] > arr[larg])
        larg = left;
    if (right < size && arr[right] > arr[larg])
        larg = right;
    if (larg != i) {
        swap(&arr[larg], &arr[i]);
        heapify(arr, size, larg);
    }
}

void heap_sort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

bool containsDuplicate(int* nums, int size) {
    heap_sort(nums, size);
    for (int i = 0; i < size - 1; i++)
        if (nums[i] == nums[i + 1])
            return true;
    return false;
}