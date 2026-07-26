class Solution {
private:
    void dfs(int open, int close, int n, string currString, vector<string>& result){
        if(2 * n == currString.size()){
            result.push_back(currString);
            return;
        }

        if(open < n){
            dfs(open + 1, close, n, currString + "(", result);
        }

        if(close < open){
            dfs(open, close + 1, n, currString + ")", result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        dfs(0,0,n,"",result);
        return result;
    }
};
