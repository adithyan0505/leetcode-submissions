class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // TC : O(n) ; SC : O(n)
        int size = nums.size();
        unordered_set<int> us;
        for (int num : nums) {
            us.insert(num);
        }
        int len = 0, maxLen = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int initNum = num;
            while(us.find(num) != us.end()) {
                us.erase(num);
                len++;
                num++;
            }
            if(len != 0) {
                if(mp.find(num) != mp.end())
                    len += mp[num];
                mp[initNum] = len;
            }  
            maxLen = maxLen < len ? len : maxLen;
            len = 0;
        }
        return maxLen;
    }
};