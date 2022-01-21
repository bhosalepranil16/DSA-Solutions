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
    void calculateSum(TreeNode *root, int sum, vector<int> &res) {
        if(root == nullptr) {
            return;
        } else if(root->left == nullptr && root->right == nullptr) {
            sum = sum*10 + root->val;
            res.push_back(sum);
        } else {
            sum = sum * 10 + root->val; 
            calculateSum(root->left, sum, res);
            calculateSum(root->right, sum, res);
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        calculateSum(root, 0, res);
        int sum = 0;
        for(int x : res) {
            sum += x;
        }
        return sum;
    }
};