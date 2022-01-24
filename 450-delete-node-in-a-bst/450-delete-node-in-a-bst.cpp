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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if(root->left == NULL) {
                TreeNode *q = root->right;
                delete root;
                return q;
            } else if(root->right == NULL) {
                TreeNode *q = root->left;
                delete root;
                return q;
            } else {
                TreeNode *q = root->right;
                while(q != nullptr && q->left != nullptr) {
                    q = q->left;
                }
                root->val = q->val;
                root->right = deleteNode(root->right, q->val);
                return root;
            }
        }
    }
};