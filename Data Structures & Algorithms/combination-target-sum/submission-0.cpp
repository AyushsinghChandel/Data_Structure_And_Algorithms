class Solution {
private: 
    void dfs(int index, vector<int>& subset, int sum, vector<int>& nums, int target, vector<vector<int>>& result){
        if(sum > target || index >= nums.size()){
            return;
        }
        if(sum == target){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(index, subset, sum + nums[index], nums, target, result);
        subset.pop_back();

        dfs(index + 1, subset, sum, nums, target, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, subset, 0, nums, target, result);
        return result;
    }
};
