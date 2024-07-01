class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size = arr.size();
        bool flag = false;
        for (int i = 0; i < size - 2; i++)
            if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2)
                flag = true;
        return flag;
    }
};