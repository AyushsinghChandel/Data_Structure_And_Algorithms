class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int ans = 0;
        while(left<right){
            int height = min(heights[left], heights[right]);
            int length = right - left;
            int vol = height * length;
            ans = max(ans,vol);
            if(heights[left]>heights[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
