class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] < 0) {
                nums[i] = -1 * nums[i];
                k--;
            }
            if(k == 0) {
                break;
            }
        }
        int sum = 0;
        if(k == 0 || k % 2 == 0) {
            for(int i=0;i<n;i++) {
                sum += nums[i];
            }
            return sum;
        }
        
        sort(nums.begin(), nums.end());
        nums[0] = -1 * nums[0];
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        return sum;
        
    }
};