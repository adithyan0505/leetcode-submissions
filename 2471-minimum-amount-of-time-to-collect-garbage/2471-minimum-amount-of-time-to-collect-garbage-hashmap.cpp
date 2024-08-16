class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int size = garbage.size();
        unordered_map<char,int> time;
        time['M'] = 0, time['P'] = 0, time['G'] = 0;
        for(int i = size-1;i >= 0;i--)
        {
            for(char ch: garbage[i])
            {
                if(time[ch] == 0)
                {
                    for(int j = 0;j < i;j++)
                        time[ch] += travel[j];
                }
                time[ch]++;
            }
        }
        return (time['M']+time['P']+time['G']);
    }
};