int addedInteger(int* nums1, int n1size, int* nums2, int n2size) {
    int min1 = nums1[0], min2 = nums2[0];
    for (int i = 0; i < n1size; i++) {
        if (min1 > nums1[i])
            min1 = nums1[i];
        if (min2 > nums2[i])
            min2 = nums2[i];
    }
    return min2 - min1;
}