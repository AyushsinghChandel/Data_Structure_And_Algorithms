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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return NULL;
        }

        int depthOfLeftNode = maxDepth(root->left);
        int depthOfRightNode = maxDepth(root->right);
        int depth = max(depthOfLeftNode, depthOfRightNode) + 1;
        return depth;
    }
};
