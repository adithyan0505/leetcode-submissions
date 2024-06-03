class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int i, j;
        unordered_map<char, int> hash;
        for (i = 0, j = 0; s[j] != '\0'; j++) {
            if (hash.find(s[j]) != hash.end()) {
                if (j - i > longest)
                    longest = j - i; 
                for (int ind = i; ind < hash[s[j]]; ind++)
                    hash.erase(s[ind]);
                i = hash[s[j]] + 1;
            }
            hash[s[j]] = j;
        }
        if (s.size() - i > longest)
            longest = s.size() - i;
        return longest;
    }
};