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
class BSTIterator {
public:
    vector<int> arr;
    int index;
    BSTIterator(TreeNode* root) {
        inorder(root, arr);
        index = 0;
    }
    
    void inorder(TreeNode *root, vector<int>& arr) {
        if(root == nullptr) {
            return;
        } 
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);   
    }
    
    int next() {
        int res = arr[index];
        index++;
        return res;
    }
    
    bool hasNext() {
        if(index >= arr.size()) {
            return false;
        } else {
            return true;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */