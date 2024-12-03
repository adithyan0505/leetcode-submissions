class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string spaced="";
        int i = 0, j = 0, n = spaces.size(), len = s.length();
        while(i < len){
            if((j < n)&&(spaces[j]==i)){
                spaced += " ";
                j++;
            }
            spaced.push_back(s[i++]);
        }
        return spaced;
    }
};