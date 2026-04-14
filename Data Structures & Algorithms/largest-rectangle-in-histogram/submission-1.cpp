class Solution {
    vector<int>prevSmallerElement (vector<int>& arr, int n){
        stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
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
    vector<int> nextSmallerElement(vector<int>& arr, int n){
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            int crr = arr[i];
            while(!st.empty() && arr[st.top()] >= crr){
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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0){
            return 0;
        }
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = 0;
        for(int i=0 ; i<n ; i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(newArea, area);
        }
        return area;
    }
};
