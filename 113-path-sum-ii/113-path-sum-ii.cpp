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
    
    void travserPaths(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>> &res) {
        if(root == nullptr) {
            return;
        } else if(root->left == nullptr && root->right == nullptr) {
            temp.push_back(root->val);
            int sum = 0;
            for(int x : temp) {
                sum += x;
            }
            if(sum == targetSum) {
                res.push_back(temp);    
            }
            return;
        } else {
            temp.push_back(root->val);
            travserPaths(root->left, targetSum, temp, res);
            travserPaths(root->right, targetSum, temp, res);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> >res;
        vector<int> temp;
        travserPaths(root, targetSum, temp, res);
        return res;
    }
};