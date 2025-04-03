class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxLen = 0, maxFreq = 0, size = s.length();
        int mp[26] = {0};
        while(right < size) {
            mp[s[right]-'A']++;
            maxFreq = max(maxFreq, mp[s[right]-'A']);
            if(right - left + 1 - maxFreq > k) {
                mp[s[left++]-'A']--;
            } else {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};