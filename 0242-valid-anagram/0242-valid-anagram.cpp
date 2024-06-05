class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(auto ch: s)
        {
            if(hash.find(ch)!=hash.end())
                hash[ch]++;
            else
                hash[ch] = 1;
        }
        for(auto ch: t)
        {
            if(hash.find(ch)!=hash.end())
            {
                hash[ch]--;
                if(hash[ch] == 0)
                    hash.erase(ch);
            }
            else
                return false;
        }
        if(hash.empty())
            return true;
        return false;
    }
};