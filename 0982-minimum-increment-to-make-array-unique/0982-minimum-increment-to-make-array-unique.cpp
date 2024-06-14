class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int max = nums[0], size = nums.size(), prev = -1, op = 0;
        for (int num : nums)
            if (num > max)
                max = num;
        vector<int> count(max + 1, 0);
        for (int num : nums)
            count[num]++;
        vector<int> freq(count);
        for (int j = 1; j < max + 1; j++)
            freq[j] += freq[j - 1];
        vector<int> out(size, -1);
        for (int num : nums)
            out[--freq[num]] = num;

        for (int ind = 1; ind < size; ind++) {
            if (out[ind] == out[ind - 1]) {
                if (prev < out[ind])
                    prev = out[ind];
                while ((prev < max) && (count[prev] != 0))
                    prev++;
                if (prev < max)
                    count[prev]++;
                else
                    prev++;
                op += prev - out[ind];
                out[ind - 1] = prev;
            }
        }
        return op;
    }
};