class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(int i:s){
            if(s.find(i-1) == s.end()){
                int currentNum = i;
                int currentStreak = 1;
                while(s.find(currentNum+1) != s.end()){
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
