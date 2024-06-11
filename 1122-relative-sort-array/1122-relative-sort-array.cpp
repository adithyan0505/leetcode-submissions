class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max = arr1[0];
        for(int num: arr1)
            if(max < num)
                max = num;
        vector<int> count(max+1,0);
        for(int num: arr1)
            count[num]++;
        vector<int> out;
        int i = 0;
        for(int j=0;j < arr2.size();j++)
        {
            while(count[arr2[j]] > 0)
            {
                out.push_back(arr2[j]);
                count[arr2[j]]--;
                i++;
            }
        }
        for(int j = i;j < arr1.size();j++)
            out.push_back(-1);
        vector<int> freq(count);
        for(int j=1;j<max+1;j++)
            freq[j] += freq[j-1];
        for(int ind = 0;ind < arr1.size();ind++)
        {
            if(count[arr1[ind]] > 0)
                out[--(freq[arr1[ind]]) + i] = arr1[ind];
        }
        return out;
    }
};