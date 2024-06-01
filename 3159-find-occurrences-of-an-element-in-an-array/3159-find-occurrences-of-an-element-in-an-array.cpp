class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> answer;
        vector<int> map;
        for(int i = 0;i < nums.size();i++)
            if(nums[i] == x)
                map.push_back(i);
        for(auto que: queries)
        {
            if((map.size() > 0)&&(map.size() > que-1))
            {
                answer.push_back(map[que-1]);
                continue;
            }
            answer.push_back(-1);
        }
        return answer;
    }
};