class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0, j = k-1, res = INT_MAX;
        while(j < n) {
            res = min(res, nums[j] - nums[i]);
            j++;
            i++;
        }
        return res;
    }
};