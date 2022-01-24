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
    
    void inorder(TreeNode *root, vector<int> &arr) {
        if(root == nullptr) {
            return;
        } else {
            inorder(root->left, arr);
            arr.push_back(root->val);
            inorder(root->right, arr);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int res = arr[1] - arr[0];
        for(int i=2;i<arr.size();i++) {
            res = min(res, arr[i]-arr[i-1]);
        }
        return res;
    }
};