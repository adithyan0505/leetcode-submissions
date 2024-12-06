int max(int a,int b){return a>b ? a:b;}

int helper(int* citations,int low,int high,int n){
    if(low <= high){
        int mid = (low+high)/2;
        if(n-mid == citations[mid])
            return n-mid;
        if(n-mid < citations[mid])
            return max(n-mid,helper(citations,low,mid-1,n));
        else
            return helper(citations,mid+1,high,n);
    }
    return 0;
}

int hIndex(int* citations, int n) {
    return helper(citations,0,n-1,n);
}