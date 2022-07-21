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
    int deepestLeavesSum(TreeNode* root) {
        
        vector<vector<int> > arr;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++) {
                TreeNode *p = q.front();
                q.pop();
                temp.push_back(p->val);
                
                if(p->left != nullptr) {
                    q.push(p->left);
                }
                
                if(p->right != nullptr) {
                    q.push(p->right);
                }
            }
            arr.push_back(temp);
        }
        
        int n = arr.size(), res = 0;
        for(int i=0;i<arr[n-1].size();i++) {
            res += arr[n-1][i];
        }
        return res;
    }
};