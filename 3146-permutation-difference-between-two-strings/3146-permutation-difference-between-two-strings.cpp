class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] = i;
        for (int i = 0; i < t.size(); i++)
            diff += abs(hash[t[i] - 'a'] - i);
        return diff;
    }
};