class Solution {
private:
    bool isPalindrome(string s, int right, int left){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(int index, string s, vector<string>& subString, vector<vector<string>>& result){
        if(index == s.size()){
            result.push_back(subString);
            return;
        }

        for(int i=index ; i<s.size(); i++){
            if(isPalindrome(s,i,index)){
                string slice = s.substr(index, i-index+1);
                subString.push_back(slice);
                dfs(i+1, s, subString, result);
                subString.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subString;

        dfs(0,s,subString,result);
        return result;
    }
};
