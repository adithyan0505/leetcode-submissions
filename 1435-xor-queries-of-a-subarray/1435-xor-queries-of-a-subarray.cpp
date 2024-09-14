class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        int arrsize = arr.size();
        for(int i=1;i < arrsize;i++)
            arr[i] = arr[i]^arr[i-1];
        for(auto q: queries){
            int ans = arr[q[1]];
            if(q[0] != 0)
                ans ^= arr[q[0]-1];
            answer.push_back(ans);
        }
        return answer;
    }
};