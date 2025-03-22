class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> mp;
        for(int num: nums) {
            if(mp.find(num) != mp.end()) {
                return true;
            }
            mp[num] = true;
        }
        return false;
    }
};