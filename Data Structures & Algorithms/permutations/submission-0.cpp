class Solution {
private:
    void dfs(vector<int> &nums, vector<bool>& used, vector<vector<int>>& result, vector<int>& permutation){
        if(permutation.size() == nums.size()){
            result.push_back(permutation);
            return;
        }

        for(int i=0 ; i<nums.size(); i++){
            if(used[i]){
                continue;
            }

            used[i] = true;
            permutation.push_back(nums[i]);
            dfs(nums, used, result, permutation);
            permutation.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);

        dfs(nums,used,result,permutation);
        return result;
    }
};
