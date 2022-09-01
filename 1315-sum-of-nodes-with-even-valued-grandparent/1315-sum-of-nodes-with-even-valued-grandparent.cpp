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
    void sumEvenGrandparentUtil(TreeNode* root, int parent, int grandParent, int &res) {
        if(root == nullptr) {
            return;
        }
        if(grandParent != -1 && grandParent % 2 == 0) {
            res += root->val;
        }
        sumEvenGrandparentUtil(root->left, root->val, parent, res);
        sumEvenGrandparentUtil(root->right, root->val, parent, res);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        sumEvenGrandparentUtil(root, -1, -1, res);
        return res;
    }
};