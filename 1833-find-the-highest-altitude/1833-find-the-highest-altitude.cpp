class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0, curr_alt = 0;
        for(int alt: gain)
        {
            curr_alt += alt;
            if(curr_alt > max_alt)
                max_alt = curr_alt;
        }
        return max_alt;
    }
};