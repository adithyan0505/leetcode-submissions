class Solution {
private:
    string multiply(string &s, int k) {
        string subs = "";
        while(k--) {
            subs += s;
        }
        return subs;
    }
public:
    string decodeString(string s) {
        stack<int> times;
        stack<char> st;
        int n = s.length();
        int it = 0;
        while(it < n) {
            int num = 0;
            while(isdigit(s[it])) {
                num *= 10;
                num += s[it] - '0';
                it++;
            }
            if(num > 0) {
                times.push(num);
            }
            if(!isdigit(s[it]) && s[it] != ']') {
                st.push(s[it]);
                it++;
            }
            if(s[it] == ']') {
                string subs = "";
                char ch;
                while((ch = st.top()) != '[') {
                    subs = ch + subs;
                    st.pop();
                } st.pop();
                subs = multiply(subs, times.top());
                times.pop();
                for(char c: subs) {
                    st.push(c);
                }
                it++;
            }
        }
        string ret = "";
        while(st.size() > 0){
            ret = st.top() + ret;
            st.pop();
        }
        return ret;
    }
};