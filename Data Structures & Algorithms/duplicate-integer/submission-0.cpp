class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int i=0 ; i<nums.size(); i++){
            if(m.count(nums[i])){
                return true;
            }
            m.insert(nums[i]);
        }
        return false;
    }
};