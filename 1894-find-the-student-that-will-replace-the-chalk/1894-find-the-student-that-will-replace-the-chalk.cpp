class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size = chalk.size();
        long long int prefix_sum[size];
        for(int i=0;i<size;i++)
            prefix_sum[i] = chalk[i];
        for(int i=1;i<size;i++)
            prefix_sum[i] += prefix_sum[i-1];
        k = k % prefix_sum[size-1];
        int left = 0, right = size-1;
        while(left <= right){
            int mid = (right-left)/2 + left;
            if(prefix_sum[mid] > k)
                right = mid-1;
            else
                left = mid + 1;
        }
        return left;
    }
};