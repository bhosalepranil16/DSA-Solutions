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
    
    int height(TreeNode *p) {
        if(p == nullptr) {
            return 0;
        }
        return 1 + max(height(p->left), height(p->right));
    }
    
    int BF(TreeNode *p) {
        if(p == nullptr) {
            return 0;
        }
        int lh, rh;
        lh = height(p->left);
        rh = height(p->right);
        return (lh-rh);
    }
    
    TreeNode* rotateLeft(TreeNode *p) {
        TreeNode *q = p->right;
        p->right = q->left;
        q->left = p;
        return q;
    }
    
    TreeNode* RR(TreeNode *p) {
        p = rotateLeft(p);
        return p;
    }
    
    TreeNode* insert(TreeNode *p, int x) {
        if(p == nullptr) {
            return new TreeNode(x);
        } else {
            p->right = insert(p->right, x);
            if(BF(p) == -2) {
                p = RR(p);
            }
            return p;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *res = nullptr;
        for(int x : nums) {
            res = insert(res, x);
        }
        return res;
    }
};