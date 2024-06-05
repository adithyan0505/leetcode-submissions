class Solution {
public:
    int min(vector<int>& nums) {
        int min = nums[0];
        for (int val : nums)
            if (min > val)
                min = val;
        return min;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> common;
        unordered_map<char, vector<int>> hash;
        for (auto ch : words[0]) {
            if (hash.find(ch) != hash.end())
                hash[ch][0]++;
            else {
                hash[ch] = vector<int>(words.size(), 0);
                hash[ch][0]++;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            for (auto ch : words[i]) {
                if (hash.find(ch) != hash.end())
                    hash[ch][i]++;
            }
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            int freq = min(it->second);
            while (freq--)
                common.push_back(string(1, it->first));
        }
        return common;
    }
};