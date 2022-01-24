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
    
    TreeNode* insert(TreeNode *root, int x) {
        if(root == nullptr) {
            return new TreeNode(x);
        } else if(root->val > x) {
            root->left = insert(root->left, x);
            return root;
        } else if(root->val < x) {
            root->right = insert(root->right, x);
            return root;
        } else {
            return root;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *res = nullptr;
        
        for(int x : preorder) {
            res = insert(res, x);
        }
        return res;
    }
};