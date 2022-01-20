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
    
    int minDe(TreeNode *root) {
        if(root == nullptr) {
            return INT_MAX - 2;
        } else if(root->left == nullptr && root->right == nullptr) {
            return 1;
        } else {
            return 1 + min(minDe(root->left), minDe(root->right));
        }
    }
    
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else {
            return minDe(root);
        }
    }
};