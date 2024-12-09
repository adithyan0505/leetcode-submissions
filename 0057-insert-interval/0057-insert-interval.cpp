class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInt) {
        vector<vector<int>> res;
        int n = intervals.size(), ind=-1;
        while((ind < n-1)&&((intervals[ind+1][0] <= newInt[0]))){
            res.push_back(intervals[ind+1]);
            ind++;
        }
        if((ind>=0)&&((intervals[ind][1] >= newInt[0])))
            res[ind][1] = max(res[ind][1],newInt[1]);
        else
            res.push_back(newInt);
        ind++;
        int ul = res.back()[1];
        while((ind < n)&&(ul >= intervals[ind][0])){
            ul = max(ul,intervals[ind][1]);
            ind++;
        }
        res[res.size()-1][1] = ul;
        while(ind < n)
            res.push_back(intervals[ind++]);
        return res;
    }
};