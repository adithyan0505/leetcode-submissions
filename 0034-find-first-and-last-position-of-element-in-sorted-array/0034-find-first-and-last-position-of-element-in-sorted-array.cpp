class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr = {-1,-1};
        int l = 0, r = nums.size()-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                if((mid!=0)&&(nums[mid-1] == target))
                    r = mid-1;
                else{
                    arr[0] = mid;
                    break;
                }
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        l = 0, r = nums.size()-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                if((mid!=nums.size()-1)&&(nums[mid+1] == target))
                    l = mid+1;
                else{
                    arr[1] = mid;
                    break;
                }
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return arr;
    }
};