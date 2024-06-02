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

int minimumAddedInteger(int* nums1, int n1size, int* nums2, int n2size) {
    heap_sort(nums1,n1size);
    heap_sort(nums2,n2size);
    int* arr = (int*)malloc(n2size*sizeof(int));
    int i,j;
    for(int h1 = 0;h1 < n1size - 1;h1++)
    {
        for(int h2 = h1+1;h2 < n1size;h2++)
        {
            i = 0;
            for(j = 0;j < n2size;j++)
            {
                if(i == h1) i++;
                if(i == h2) i++;
                arr[j] = nums2[j] - nums1[i++];
                if(j > 0)
                    if(arr[j] != arr[j-1])
                        break;
            }
            if(j == n2size)
                return arr[0];
        }
    }
    return 0;
}