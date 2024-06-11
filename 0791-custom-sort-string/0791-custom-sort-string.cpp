class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (auto ch : s)
            count[ch - 'a']++;
        vector<char> out;
        for (auto ch : order) {
            while (count[ch - 'a'] > 0) {
                out.push_back(ch);
                count[ch - 'a']--;
            }
        }
        for (auto ch : s) {
            if (count[ch - 'a'] > 0) {
                out.push_back(ch);
                count[ch - 'a']--;
            }
        }
        return string(out.begin(), out.end());
    }
};