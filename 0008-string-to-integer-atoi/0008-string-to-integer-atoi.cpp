class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1;
        bool flag = 0;
        for(int i = 0; s[i] != '\0'; i++){
            char ch = s[i];
            if(isdigit(ch)){
                flag = 1;
                if((sign==1) && (INT_MAX < num*10 + ch - '0')){
                    return INT_MAX;
                }else if((sign==-1) && (-1*num*10 - ch + '0' < INT_MIN)){
                    return INT_MIN;
                }
                num = num*10 + ch - '0';
            }
            else if(!flag){
                if(ch==' ') continue;
                flag = 1;
                if(ch=='-')
                    sign = -1;
                else if(ch=='+')
                    continue;
                else if(ch!=' ')
                    break;
            }else break;
        }
        num = num * sign;
        return int(num);
    }
};