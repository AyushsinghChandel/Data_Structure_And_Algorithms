class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for(int i=0 ; i<n ; i++){
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        stack<float> st;
        for(int i=0 ; i<n ; i++){
            float time = (float)(target - cars[i].first)/cars[i].second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
