class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l < r){
            if(nums[l] < nums[r])
                return nums[l];
            int m = (l+r)/2;
            if(nums[l]==nums[m] && nums[m]==nums[r]){
                l++; r--;
                continue;
            }
            if(nums[m] <= nums[r])
                r = m;
            else
                l = m+1;
        }
        return nums[l];
    }
};