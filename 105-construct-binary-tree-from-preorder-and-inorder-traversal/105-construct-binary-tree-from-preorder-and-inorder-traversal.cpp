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
    
    TreeNode* cTree(vector<int>& preorder, vector<int>& inorder, int &preIndex, int is, int ie) {
        if(is > ie) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        int inIndex;
        for(int i=is;i<=ie;i++) {
            if(root->val == inorder[i]) {
                inIndex = i;
                break;
            }
        }
        
        root->left = cTree(preorder, inorder, preIndex, is, inIndex-1);
        root->right = cTree(preorder, inorder, preIndex, inIndex+1, ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        return cTree(preorder, inorder, preIndex, 0, n-1);
    }
};