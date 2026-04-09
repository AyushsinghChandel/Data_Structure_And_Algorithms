class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int n= nums.size();
        // unordered_map<int, int> map;
        // for(int i:nums){
        //     map[i]++;
        // }
        // vector<vector<int>>bucket(n+1);
        // for(auto const& [num,freq] : map){
        //     bucket[freq].push_back(num);
        // }
        // vector<int> result;
        // for(int i=n; i>=0; i--){
        //     for(int num : bucket[i]){
        //         result.push_back(num);
        //         if(result.size() == k){
        //             return result;
        //         }
        //     }
        // }
        // return result;


        int n = nums.size();
        unordered_map<int, int> m;
        for(auto i:nums){
            m[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto const& [num, freq]: m){
            minHeap.push({freq,num});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
