class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> rep(nums.size() + 1);
        for (auto it : mp) {
            rep[it.second].push_back(it.first);
        }
        vector<int> res;
        for (int i = nums.size(); i > 0; i--) {
            if (rep[i].size() > 0) {
                for (int num : rep[i]) {
                    if (k > 0) {
                        res.push_back(num);
                        k--;
                    } else
                        break;
                }
            }
            if (k == 0)
                break;
        }
        return res;
    }
};