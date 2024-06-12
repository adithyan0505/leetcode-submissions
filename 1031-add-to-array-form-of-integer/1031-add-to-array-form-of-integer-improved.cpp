class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int sum;
        for (int i = num.size() - 1; i > -1 && k != 0; i--) {
            sum = num[i] + k % 10;
            num[i] = sum % 10;
            k /= 10;
            k += sum / 10;
        }
        while (k != 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};