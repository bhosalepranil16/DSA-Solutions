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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == nullptr) {
            return res;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int temp = INT_MIN;
            for(int i=0;i<size;i++) {
                TreeNode *curr = q.front();
                q.pop();
                temp = max(temp, curr->val);
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};