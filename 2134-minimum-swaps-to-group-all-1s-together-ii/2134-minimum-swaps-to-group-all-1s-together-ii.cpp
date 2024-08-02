class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size(), ones = 0;
        for(int num: nums)
            if(num==1)
                ones++;
        int left = 0, right = 0, minim = size, swap = 0;
        while(left < size)
        {
            if(nums[right%size]==0 && ones)
                swap++;
            if(right - left + 1 >= ones)
            {
                minim = min(minim,swap);
                if(nums[left]==0 && ones)
                    swap--;
                left++;
            }
            right++;
        }
        return minim;
    }
};