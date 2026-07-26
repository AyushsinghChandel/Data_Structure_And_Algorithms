class Solution {
private: 
    void dfs(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result){
        if(nums.size() <= index){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(index+1, nums, subset, result);

        subset.pop_back();
        dfs(index+1, nums, subset, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(0, nums, subset, result);
        return result;
    }
};
