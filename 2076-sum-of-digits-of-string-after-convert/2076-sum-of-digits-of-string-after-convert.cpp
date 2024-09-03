class Solution {
public:
    int getLucky(string s, int k) {
        int result = 0;
        for(char ch: s){
            int num = ch - 'a' + 1;
            while(num){
                result += num%10;
                num /= 10;
            }
        }
        k--;
        printf("%d ",result);
        while(k--){
            int temp = 0;
            while(result){
                temp += result%10;
                result /= 10;
            }
            result = temp;
            printf("%d ",result);
        }
        return result;
    }
};