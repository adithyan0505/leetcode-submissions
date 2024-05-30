void sortColors(int* nums, int size) {
    int p1=0, p2, temp;
    for (int num = 0; num <= 2; num++) {
        for (p2 = p1 + 1; p1 < size - 1; p1++) {
            if (nums[p1] != num) {
                while ((p2 < size) && (nums[p2] != num))
                    p2++;
                if (p2 != size) {
                    temp = nums[p1];
                    nums[p1] = nums[p2];
                    nums[p2] = temp;
                }
                else
                    break;
            }
            else
                p2++;
        }
    }
}