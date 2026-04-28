class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int i=0 ; i<nums.size() ; i++){
            if(m.count(nums[i])){
                return nums[i];
            }
            m.insert(nums[i]);
        }
        return -1;
    }
};
