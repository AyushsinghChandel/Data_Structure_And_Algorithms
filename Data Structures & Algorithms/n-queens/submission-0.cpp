class Solution {
private:
    void dfs(int row, vector<string>& board, vector<vector<string>>& result, unordered_set<int>& col, unordered_set<int>& posDia, unordered_set<int>& negDia, int n){
        if(row == n){
            result.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(col.count(c) || posDia.count(row + c) || negDia.count(row - c)){
                continue;
            }
            col.insert(c);
            posDia.insert(row + c);
            negDia.insert(row - c);
            board[row][c] = 'Q';
            dfs(row + 1, board, result, col, posDia, negDia, n);
            col.erase(c);
            posDia.erase(row + c);
            negDia.erase(row - c);
            board[row][c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n,'.'));
        unordered_set<int> col;
        unordered_set<int> posDia;
        unordered_set<int> negDia;

        dfs(0, board, result, col, posDia, negDia, n);
        return result;
    }
};
