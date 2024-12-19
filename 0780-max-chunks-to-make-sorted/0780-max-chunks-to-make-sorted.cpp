class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int rmax=0,count=0;
        for(int i=0;i<n;i++){
            rmax = max(rmax,arr[i]);
            count += rmax==i ? 1:0;
        }
        return count;
    }
};