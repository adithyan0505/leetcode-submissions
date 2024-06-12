class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = max(num.size(), to_string(k).size());
        vector<int> out(n + 1, 0);
        int carry = 0, sum;
        if (n == num.size()) {
            for (int ind = num.size() - 1; ind >= 0; ind--) {
                sum = num[ind] + k % 10 + carry;
                out[ind + 1] = sum % 10;
                carry = sum / 10;
                k = k / 10;
            }
            out[0] = carry;
        } else {
            int number = 0;
            for (int d : num)
                number = 10 * number + d;
            sum = number + k;
            for (int i = out.size() - 1; i >= 0; i--) {
                out[i] = sum % 10;
                sum = sum / 10;
            }
        }
        if (out[0] != 0)
            return out;
        return vector<int>(out.begin() + 1, out.end());
    }
};