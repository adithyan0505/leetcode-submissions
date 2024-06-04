class Solution {
public:
    int longestPalindrome(string s) {
        int longest = 0;
        unordered_map<char,int> hash;
        for(auto i: s)
        {
            if(hash.find(i)!=hash.end())
                hash[i]++;
            else
                hash[i] = 1;
        }
        int add = 0;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            longest += 2*(it->second/2);
            if(it->second%2 != 0)
                add = 1;
        }
        longest += add;
        return longest;
    }
};