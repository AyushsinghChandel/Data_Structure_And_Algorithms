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

class Codec {
    private: 
    void serializeHelper(TreeNode* node, ostringstream& out){
        if(node == nullptr){
            out<<"N ";
            return;
        }
        out<<node->val<<" ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }
    TreeNode* deSerializeHelper(istringstream& in){
        string val;
        in>>val;
        if(val == "N"){
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deSerializeHelper(in);
        node->right = deSerializeHelper(in);
        
        return node;
    } 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data); 
        return deSerializeHelper(in);
    }
};
