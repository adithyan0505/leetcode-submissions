class Solution {
public:
    void reverse(string& s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            char temp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = temp;
        }
    }
    string finalString(string s) {
        string str("");
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == 'i')
                reverse(str);
            else
                str.push_back(s[i]);
        }
        return str;
    }
};