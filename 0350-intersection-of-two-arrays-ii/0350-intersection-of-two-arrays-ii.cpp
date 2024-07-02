class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p1 = 0, p2 = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        while(p1 < size1 && p2 < size2)
        {
            if(nums1[p1] == nums2[p2])
            {
                out.push_back(nums1[p1++]);
                p2++;
            }
            else if(nums1[p1] < nums2[p2])
                p1++;
            else
                p2++;
        }
        return out;
    }
};