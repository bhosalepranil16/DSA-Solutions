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
    
    int goodNodesUtil(TreeNode* root, int great) {
        if(root == nullptr) {
            return 0;
        }
        if(root->val >= great) {
            return 1 + goodNodesUtil(root->left, root->val) + goodNodesUtil(root->right, root->val);
        } else {
            return goodNodesUtil(root->left, great) + goodNodesUtil(root->right, great);
        }   
    }
    
    int goodNodes(TreeNode* root) {
        return goodNodesUtil(root, root->val);
    }
};