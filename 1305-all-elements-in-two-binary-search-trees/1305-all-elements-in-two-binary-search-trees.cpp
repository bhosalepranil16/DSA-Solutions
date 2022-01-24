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
    
    void inorder(TreeNode *root, vector<int> &arr) {
        if(root == nullptr) {
            return;
        } else {
            inorder(root->left, arr);
            arr.push_back(root->val);
            inorder(root->right, arr);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2, arr;
        inorder(root1, arr1);
        inorder(root2, arr2);
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(arr1[i] <= arr2[j]) {
                arr.push_back(arr1[i]);
                i++;
            } else {
                arr.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < n) {
            arr.push_back(arr1[i]);
            i++;
        }
        
        while(j < m) {
            arr.push_back(arr2[j]);
            j++;
        }
        return arr;
    }
};