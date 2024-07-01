class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for (int i = 0; i < 26; i++)
            hash[order[i]] = i;
        bool flag = true;
        int size = words.size();
        for (int i = 0; i < size - 1; i++) {
            int wsize = min(words[i].size(), words[i + 1].size());
            bool equal = true;
            for (int j = 0; j < wsize; j++) {
                if (hash[words[i][j]] < hash[words[i + 1][j]]) {
                    equal = false;
                    break;
                } else if (hash[words[i][j]] > hash[words[i + 1][j]]) {
                    flag = false;
                    equal = false;
                    break;
                }
            }
            if (flag) {
                if (equal) {
                    if (words[i].size() > words[i + 1].size()) {
                        flag = false;
                        break;
                    }
                }
            } else
                break;
        }
        return flag;
    }
};