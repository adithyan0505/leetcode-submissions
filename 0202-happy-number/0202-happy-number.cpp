class Solution {
public:
    int squaresum(int n) {
        int temp = 0;
        while (n > 0) {
            temp += pow(n % 10, 2);
            n = n / 10;
        }
        return temp;
    }
    bool find(vector<int>& array, int target) {
        int l = 0, r = array.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid] == target)
                return true;
            else if (target > array[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    bool isHappy(int n) {
        bool flag = false;
        vector<int> track;
        while (!(find(track, n) || flag)) {
            track.push_back(n);
            n = squaresum(n);
            if (n == 1)
                flag = true;
        }
        return flag;
    }
};