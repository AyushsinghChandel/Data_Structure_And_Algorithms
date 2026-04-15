class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int> countS1(26,0);
        vector<int> countS2(26,0);

        for(int i = 0 ; i<s1.length() ; i++){
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }

        if(countS1 == countS2){
            return true;
        }

        for(int i=s1.length(); i<s2.length(); i++){
            countS2[s2[i] - 'a']++;
            int left = i - s1.length();
            countS2[s2[left] - 'a']--;
            if(countS1 == countS2){
            return true;
        } 
        }
        return false;
    }
};
