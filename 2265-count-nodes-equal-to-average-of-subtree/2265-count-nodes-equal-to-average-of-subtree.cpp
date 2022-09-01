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
    
    pair<int, int> averageOfSubtreeUtil(TreeNode *root, int &res) {
        if(root == nullptr) {
            return make_pair(0, 0);
        }
        pair<int, int> p1 = averageOfSubtreeUtil(root->left, res);
        pair<int, int> p2 = averageOfSubtreeUtil(root->right, res);
        
        pair<int, int> p3 = make_pair(p1.first + p2.first + root->val, p1.second + p2.second + 1);
        if(p3.first / p3.second == root->val) {
            res++;
        }
        return p3;
    }
    
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        pair<int, int> p = averageOfSubtreeUtil(root, res);
        return res;
    }
};