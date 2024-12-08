class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> merged;
        int i=0, n=arr.size();
        while(i < n){
            vector<int> inter = {arr[i][0]};
            int j = 1;
            while((i+j < n)&&(arr[i][1] >= arr[i+j][0])){
                if(arr[i][1] >= arr[i+j][1])
                    j++;
                else{
                    i += j;
                    j = 1;
                }
            }
            inter.push_back(arr[i][1]);
            merged.push_back(inter);
            i += j;
        }
        return merged;
    }
};