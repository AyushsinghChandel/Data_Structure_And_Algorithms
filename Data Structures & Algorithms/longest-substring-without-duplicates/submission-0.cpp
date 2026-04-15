class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int left = 0;
        int maxLen = 0;
        for(int right = 0 ; right < s.size() ; right++){
            while(ss.find(s[right]) != ss.end()){
                ss.erase(s[left]);
                left++;
            }
            ss.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
