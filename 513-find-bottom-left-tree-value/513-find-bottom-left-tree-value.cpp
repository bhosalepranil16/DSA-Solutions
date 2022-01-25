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
    
    
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int> > arr;
        
        while(!que.empty()) {
            int x = que.size();
            vector<int> temp;
            for(int i=0;i<x;i++) {
                TreeNode *curr = que.front();
                que.pop();
                if(curr->left != nullptr) {
                    que.push(curr->left);
                }
                if(curr->right != nullptr) {
                    que.push(curr->right);
                }
                temp.push_back(curr->val);
            }
            arr.push_back(temp);
        }
        int n = arr.size();
        return arr[n-1][0];
    }
};