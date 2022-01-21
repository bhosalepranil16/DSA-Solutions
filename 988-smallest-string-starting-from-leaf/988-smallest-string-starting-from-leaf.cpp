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
    
    void traversePath(TreeNode* root, string str, vector<string> &res) {
        if(root == nullptr) {
            return;
        } else if(root->left == nullptr && root->right == nullptr) {
            str += (char) root->val + 'a';
            res.push_back(str);
            return;
        } else {
            str += (char) root->val + 'a';
            traversePath(root->left, str, res);
            traversePath(root->right, str, res);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        traversePath(root, "", res);
        int n = res.size();
        for(int i=0;i<n;i++) {
            reverse(res[i].begin(), res[i].end());
            cout << res[i] << " ";
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};