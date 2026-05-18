/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateBranch(root, maxSum);
        return maxSum;
    }
    int calculateBranch(TreeNode* root, int& maxSum){
        if(root == nullptr){
            return 0;
        }

        int leftBranch = max(0,calculateBranch(root->left, maxSum));
        int rightBranch = max(0,calculateBranch(root->right, maxSum));
        
        int curr = root->val + leftBranch + rightBranch;

        maxSum = max(curr, maxSum);
        return root->val + max(leftBranch, rightBranch);
    }
};
