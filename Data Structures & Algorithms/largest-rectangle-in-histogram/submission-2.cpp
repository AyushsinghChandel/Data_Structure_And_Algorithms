class Solution {
public:
vector<int>prevSmallerElement(vector<int>& arr, int n){
    stack<int> st;
    vector<int> ans(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>nextSmallerElement(vector<int>& arr, int n){
    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0){
            return 0;
        }
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights ,n);

        int maxArea = 0;
        for(int i=0 ; i<n ; i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};