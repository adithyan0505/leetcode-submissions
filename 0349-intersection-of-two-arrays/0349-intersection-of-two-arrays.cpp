class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> hash;
        vector<int> array;
        for (int num : nums1)
            if (hash.find(num) == hash.end())
                hash[num] = false;
        for (int num : nums2)
            if (hash.find(num) != hash.end())
                hash[num] = true;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (it->second)
                array.push_back(it->first);
        }
        return array;
    }
};