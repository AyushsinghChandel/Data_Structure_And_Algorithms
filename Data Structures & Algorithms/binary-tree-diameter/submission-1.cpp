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
// int height(TreeNode* root){
//     if(root == nullptr){
//         return 0;
//     }
//     int heightOfLeftNode = height(root->left);
//     int heightOfRightNode = height(root->right);
//     int ans = max(heightOfLeftNode, heightOfRightNode) + 1;
//     return ans;
// }
int calculateDiameter(TreeNode* root, int &max_diameter){
    if(root == nullptr){
        return 0;
    }

    int leftNode = calculateDiameter(root->left, max_diameter);
    int rightNode = calculateDiameter(root->right, max_diameter);

    max_diameter = max(max_diameter, rightNode + leftNode);

    return max(leftNode, rightNode) + 1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == nullptr){
        //     return 0;
        // }

        // int option1 = diameterOfBinaryTree(root->left);
        // int option2 = diameterOfBinaryTree(root->right);
        // int option3 = height(root->left) + height(root->right);
        // return max(option1, max(option2, option3));

        int max_diameter = 0;
        calculateDiameter(root, max_diameter);
        return max_diameter;
    }
};
