class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        unordered_map<string,vector<int>> mp;
        int n = strs.size();
        for(int i = 0;i < n;i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        for(auto it: mp) {
            vector<string> o;
            for(int k : it.second) {
                o.push_back(strs[k]);
            }
            out.push_back(o);
        }
        return out;
    }
};