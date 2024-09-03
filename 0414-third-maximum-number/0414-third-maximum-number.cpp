class Solution {
public:
    void Heapify(vector<int>& arr,int size,int i){
        int largest = i;
        int left = 2*i + 1, right = 2*i + 2;
        if((left < size) && (arr[largest] < arr[left]))
            largest = left;
        if((right < size) && (arr[largest] < arr[right]))
            largest = right;
        if(largest != i){
            std::swap(arr[largest],arr[i]);
            Heapify(arr,size,largest);
        }
    }
    void buildHeap(vector<int>& arr,int size){
        for(int i = (size-1)/2;i >= 0;i--)
            Heapify(arr,size,i);
    }
    int thirdMax(vector<int>& nums) {
        int size = nums.size();
        buildHeap(nums,size);
        stack<int> max_list;
        while(max_list.size() < 3 && size > 0){
            if(max_list.empty() || max_list.top() != nums[0])
                max_list.push(nums[0]);
            std::swap(nums[0],nums[size-1]);
            Heapify(nums,--size,0);
        }
        if(max_list.size()==3)
            return max_list.top();
        while(max_list.size() != 1)
            max_list.pop();
        return max_list.top();
    }
};