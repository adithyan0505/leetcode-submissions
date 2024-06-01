/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

int find_ind(int* array,int size,int val)
{
    int ind;
    for(ind=0;ind < size;ind++)
        if(array[ind] == val)
            break;
    return ind;
}

int* twoSum(int* nums, int size, int target, int* returnSize) {
    int* copy = (int*)malloc(size*sizeof(int));
    for(int i=0;i < size;i++)
        copy[i] = nums[i];
    *returnSize = 2;
    int* arr = (int*)malloc(*returnSize * sizeof(int));
    heap_sort(nums,size);
    int left = 0, right = size-1;
    while(left < right)
    {
        if(nums[right] + nums[left] == target)
        {
            arr[0] = find_ind(copy,size,nums[left]);
            if(nums[left] == nums[right])
                arr[1] = find_ind(copy+arr[0]+1,size-arr[0]-1,nums[right]) + arr[0] + 1;
            else
                arr[1] = find_ind(copy,size,nums[right]);
            break;
        }
        else if(nums[right] + nums[left] > target)
            right--;
        else
            left++;
    }
    free(copy);
    return arr;
}