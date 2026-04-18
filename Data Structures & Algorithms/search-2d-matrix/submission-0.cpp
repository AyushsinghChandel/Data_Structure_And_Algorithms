class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = (row * col) - 1;

        while(left <= right){
            int mid = left + (right-left)/2;
            int midRow = mid/col;
            int midCol = mid%col;

            if(target == matrix[midRow][midCol]){
                return true;
            }
            else if(target > matrix[midRow][midCol]){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
