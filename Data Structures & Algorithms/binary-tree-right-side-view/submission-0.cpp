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
void printRightView(TreeNode* root, int level, vector<int> &rightView){
    if(root == nullptr){
        return;
    }

    if(level == rightView.size()){
        rightView.push_back(root->val);
    }

    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        printRightView(root, 0, rightView);
        return rightView;
    }
};
