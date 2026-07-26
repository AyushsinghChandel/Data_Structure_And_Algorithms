class Solution {
private:
    void dfs(int index, vector<int>& subset, int sum, vector<int>& candidates, int target, vector<vector<int>>& result){
        if( target < sum){
            return;
        }
        if(target == sum){
            result.push_back(subset);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(sum + candidates[i] > target){
                break;
            }
            subset.push_back(candidates[i]);
            dfs(i+1, subset, sum + candidates[i], candidates, target, result);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(0, subset, 0, candidates, target, result);
        return result;
    }
};
