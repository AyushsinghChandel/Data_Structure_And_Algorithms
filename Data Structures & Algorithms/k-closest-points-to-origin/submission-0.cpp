class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0 ; i<points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];

            int squaredDistance = (x * x) + (y * y);
            maxHeap.push({squaredDistance, i});

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            int index = maxHeap.top().second;
            result.push_back(points[index]);
            maxHeap.pop();
        }
        return result;
    }
};
