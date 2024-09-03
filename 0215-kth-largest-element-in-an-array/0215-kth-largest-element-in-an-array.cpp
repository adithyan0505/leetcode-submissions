class Solution {
public:
    void swap(int* a,int* b){
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
    void Heapify(vector<int>& arr,int size,int i){
        int largest = i;
        int left = 2*i + 1, right = 2*i + 2;
        if((left < size) && (arr[largest] < arr[left]))
            largest = left;
        if((right < size) && (arr[largest] < arr[right]))
            largest = right;
        if(largest != i){
            swap(&arr[largest],&arr[i]);
            Heapify(arr,size,largest);
        }
    }
    void buildHeap(vector<int>& arr,int size){
        for(int i = (size-1)/2;i >= 0;i--)
            Heapify(arr,size,i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        buildHeap(nums,size);
        while(--k){
            swap(&nums[0],&nums[size-1]);
            Heapify(nums,--size,0);
        }
        return nums[0];
    }
};