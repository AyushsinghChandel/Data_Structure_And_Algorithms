class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(auto i : tasks){
            counts[i]++;
        }

        priority_queue<int> maxHeap;
        for(auto pair : counts){
            maxHeap.push(pair.second);
        }

        queue<pair<int, int>> coolDown;
        int time = 0;

        while(!maxHeap.empty() || !coolDown.empty()){
            time++;
            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
            if(count>0){
                coolDown.push({count, time+n});
            }
            }
            if(!coolDown.empty() && coolDown.front().second == time){
                maxHeap.push(coolDown.front().first);
                coolDown.pop();
            }
        }
        return time;
    }
};
