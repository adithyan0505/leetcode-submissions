class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        unordered_set<int> us;
        int min = INT_MAX, max = INT_MIN;
        for (int num : nums) {
            us.insert(num);
            if (num < min)
                min = num;
            if (num > max)
                max = num;
        }
        int len = 0, maxLen = 0;
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            while(us.find(num) != us.end()) {
                len++;
                num++;
            }
            maxLen = maxLen < len ? len : maxLen;
            len = 0;
        }
        return maxLen;
    }
};