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
    
    void calculatePaths(TreeNode* root, vector<string> &res, string ans) {
        if(root == nullptr) {
            return;
        } else if(root->left == nullptr && root->right == nullptr) {
            ans += "->" + to_string(root->val);
            res.push_back(ans);
        } else {
            ans += "->" + to_string(root->val);
            calculatePaths(root->left, res, ans);
            calculatePaths(root->right, res, ans);
        } 
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
        vector<string> res;
        calculatePaths(root, res, ans);
        for(int i=0;i<res.size();i++) {
            res[i] = res[i].substr(2);
        }
        return res;
    }
};