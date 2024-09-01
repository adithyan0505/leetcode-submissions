class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int index = 0, size = original.size();
        vector<vector<int>> array;
        if(m * n != size)
            return array;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(array.size() <= i)
                    array.push_back({original[index++]});
                else
                    array[i].push_back(original[index++]);
            }
        }
        return array;
    }
};