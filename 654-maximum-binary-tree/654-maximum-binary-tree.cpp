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
    
    TreeNode* buildTree(vector<int>& nums, int low, int high) {
        if(low > high) {
            return nullptr;
        }
        int maxIndex = low;
        for(int i=low+1;i<=high;i++) {
            if(nums[maxIndex] < nums[i]) {
                maxIndex = i;
            }
        }
        
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = buildTree(nums, low, maxIndex - 1);
        root->right = buildTree(nums, maxIndex+1, high);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};