class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int l=0,r=arr.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(arr[m]==key)
                return true;
            if(arr[l]==arr[m] && arr[m]==arr[r]){
                l++; r--;
                continue;
            }
            if(arr[m] > key){
                if(arr[l] > key && arr[l] <= arr[m])
                    l = m+1;
                else
                    r = m-1;
            }else{
                if(arr[r] < key && arr[m] <= arr[r])
                    r = m-1;
                else
                    l = m+1;
            }
        }
        return false;
    }
};