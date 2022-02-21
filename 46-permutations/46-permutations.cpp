class Solution {
public:
    
    void solvePermutations(vector<int>& nums, int l, int r, vector<vector<int> > &res) {
        if(l == r) {
            vector<int> temp = nums;
            res.push_back(temp);
            return;
        }
        for(int i=l;i<=r;i++) {
            swap(nums[i], nums[l]);
            solvePermutations(nums, l+1, r, res);
            swap(nums[i], nums[l]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        solvePermutations(nums, 0, nums.size()-1, res);
        return res;
    }
};