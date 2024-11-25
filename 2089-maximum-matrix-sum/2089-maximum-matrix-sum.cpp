class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), count = 0, minabs = INT_MAX;
        long long msum = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int curr = matrix[i][j];
                msum += abs(curr);
                if(curr < 0)
                    count++;
                if(abs(curr) < minabs)
                    minabs = abs(curr);
            }
        }
        if(count%2 != 0)
            msum -= 2*minabs;
        return msum;
    }
};