class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string s("");
        for(char ch: s1){
            if(ch!=' ')
                s.push_back(ch);
            else{
                mp[s]++;
                s = "";
            }
        }
        mp[s]++;
        s = "";
        for(char ch: s2){
            if(ch!=' ')
                s.push_back(ch);
            else{
                mp[s]++;
                s = "";
            }
        }
        mp[s]++;
        vector<string> uncommon;
        for(auto& it: mp){
            if(it.second==1)
                uncommon.push_back(it.first);
        }
        return uncommon;
    }
};