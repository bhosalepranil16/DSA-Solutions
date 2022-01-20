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

    bool preOrder(TreeNode *p, TreeNode *q) {
        if(p == nullptr && q == nullptr) {
            return true;
        } else if(p == nullptr || q == nullptr) {
            return false;
        } else if(p->val != q->val) {
            return false;
        } else {
            return preOrder(p->left, q->left) && preOrder(p->right, q->right);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preOrder(p, q);
    }
};