class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0, n=intervals.size();
        int count = 0;
        while(i < n){
            int end = intervals[i][1];
            while((i < n-1)&&(intervals[i+1][0] < end)){
                end = min(end,intervals[i+1][1]);
                count++; i++;
            }
            i++;
        }
        return count;
    }
};