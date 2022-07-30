class Solution {
public:
    
    void reverse(vector<int> &nums, int low, int high) {
        while(low < high) {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i = n - 2;
        
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        if(i >= 0) {
            int j = n - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums, i+1, n-1);
    }
};