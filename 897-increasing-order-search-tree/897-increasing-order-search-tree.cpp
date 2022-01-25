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
    
    void inorder(TreeNode *root, vector<TreeNode*> &arr) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root, arr);
        root = arr[0];
        root->left = nullptr;
        TreeNode *tail = root;
        int n = arr.size();
        for(int i=1;i<n;i++) {
            arr[i]->left = nullptr;
            tail->right = arr[i];
            tail = tail->right;
        }
        return root;
    }
};