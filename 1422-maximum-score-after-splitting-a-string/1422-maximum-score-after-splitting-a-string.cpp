class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int prefix[n];
        prefix[0] = s[0]=='0' ? 1:0;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + (s[i]=='0' ? 1:0);
        }
        int score = 0;
        for(int i=0;i<n-1;i++){
            int curr = 2*prefix[i] + n - 1 - i - prefix[n-1];
            score = curr > score ? curr:score;
        }
        return score;
    }
};