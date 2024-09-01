class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int ind = 0;
        int jump = nums[ind];
        if(ind + jump >= size - 1)
            return true;
        for(int i=1;i<=jump;i++){
            ind++;
            if(ind == size-1)
                return true;
            if(nums[ind] > jump-i){
                jump = nums[ind];
                i=1;i--;
            }
        }
        return false;
    }
};