class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // using set to track occurance
        unordered_set<int> s;
        for(int num: nums) {
            if(s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};