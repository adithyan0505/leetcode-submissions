class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int hi=0, n=citations.size();
        while(hi < n && hi < citations[n-hi-1]) 
            hi++;
        return hi;
    }
};