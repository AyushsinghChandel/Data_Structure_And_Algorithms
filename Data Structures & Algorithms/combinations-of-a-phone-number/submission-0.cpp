class Solution {
private:
    void dfs(int index, string digits, string currStr, vector<string>& pad, vector<string>& result){
        if(index == digits.length()){
            result.push_back(currStr);
            return;
        }

        char currDigit = digits[index];
        string letters = pad[currDigit - '0'];
        for(char letter : letters){
            dfs(index+1, digits, currStr + letter, pad, result);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> result;
        vector<string> pad = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "xwyz"};

        dfs(0, digits, "", pad, result);
        return result;
    }
};
