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
    
    void inorder(TreeNode *root, unordered_map<int, int> &mp) {
        if(root == nullptr) {
            return;
        } else {
            inorder(root->left, mp);
            mp[root->val]++;
            inorder(root->right, mp);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> mp;
        inorder(root, mp);
        int maxCount = INT_MIN;
        for(pair<int, int> a : mp) {
            maxCount = max(maxCount, a.second);
        }
        for(pair<int, int> a : mp) {
            if(a.second == maxCount) {
                res.push_back(a.first);
            }
        }
        return res;
    }
};