class Solution {
public:
    string makeFancyString(string s) {
        string fancy = "";
        int len = s.size(), lenf = 0;
        for(int i=0;i<len;i++){
            if(lenf >= 2 && s[i]==fancy[lenf-1] && s[i]==fancy[lenf-2])
                continue;
            fancy.push_back(s[i]);
            lenf++;
        }
        return fancy;
    }
};