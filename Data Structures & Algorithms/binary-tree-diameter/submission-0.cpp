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
int height(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int heightOfLeftNode = height(root->left);
    int heightOfRightNode = height(root->right);
    int ans = max(heightOfLeftNode, heightOfRightNode) + 1;
    return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right);
        return max(option1, max(option2, option3));
    }
};
