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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        
        que.push(root);
        
        while(!que.empty()) {
            int x = que.size();
            double sum = 0;
            for(int i=0;i<x;i++) {
                TreeNode *p = que.front();
                que.pop();
                sum += p->val;
                if(p->left != nullptr) {
                    que.push(p->left);
                }
                if(p->right != nullptr) {
                    que.push(p->right);
                }
            }
            res.push_back(sum/x);
        }
        return res;
    }
};