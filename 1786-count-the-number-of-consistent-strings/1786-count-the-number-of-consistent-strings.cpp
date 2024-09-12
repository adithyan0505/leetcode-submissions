class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int H[26] = {0};
        for(char ch: allowed)
        {
            if(ch!='\0')
                H[ch-'a']=1;
        }
        int count = 0;
        bool flag = 1;
        for(auto word: words){
            for(char ch: word){
                if(ch!='\0' && !H[ch-'a']){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                count++;
            flag = 1;
        }
        return count;
    }
};