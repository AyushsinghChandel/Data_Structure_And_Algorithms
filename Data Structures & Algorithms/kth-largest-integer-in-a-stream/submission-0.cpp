class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int capacity;
public:
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(int i=0; i<nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(capacity < minHeap.size()){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
