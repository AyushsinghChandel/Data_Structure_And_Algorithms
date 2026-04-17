class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || t.size() > s.size()){
            return "";
        }

        vector<int> tCount(128,0);
        for(char c:t){
            tCount[c]++;
        }

        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        int counter = t.length();
        while(right < s.size()){
            if(counter != 0 && tCount[s[right]]>0){
                counter--;
            }
            tCount[s[right]]--;
            right++;

            while(counter == 0){
                if(right - left < minLen){
                    minStart = left;
                    minLen = right - left;
                }
                tCount[s[left]]++;
                if(tCount[s[left]]>0){
                    counter++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
