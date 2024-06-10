class Solution {
public:
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int i = -1, j = 0;
        while (j < nums.size()) {
            if (nums[j] != 0)
                swap(&nums[++i], &nums[j++]);
            else
                j++;
        }
    }
};