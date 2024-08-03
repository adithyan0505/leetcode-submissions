class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        int size = target.size();
        bool possible = true;
        for(int i = 0;i < size;i++)
        {
            if(arr[i] != target[i])
            {
                possible = false;
                break;
            }
        }
        return possible;
    }
};