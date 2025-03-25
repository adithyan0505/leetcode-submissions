class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC : O(n) ; SC : O(n)
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);
        prefix[0]=nums[0], suffix[size-1]=nums[size-1];
        for(int i=1;i<size;i++) {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[size-1-i] = suffix[size-i] * nums[size-1-i];
        }
        vector<int> res;
        for(int i=0;i<size;i++) {
            if(i == 0) {
                res.push_back(suffix[i+1]);
            } else if(i == size-1) {
                res.push_back(prefix[i-1]);
            } else {
                res.push_back(prefix[i-1] * suffix[i+1]);
            }
        }
        return res;
    }
};