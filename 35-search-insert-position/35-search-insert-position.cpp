class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        
        if(target < nums[0]) {
            return 0;
        }
        if(target > nums[high]) {
            return high + 1;
        }
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                ans = mid;
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};