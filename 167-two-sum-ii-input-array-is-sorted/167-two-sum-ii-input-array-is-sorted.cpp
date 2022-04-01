class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int low = 0, high = numbers.size() - 1;
        
        while(low < high) {
            int sum = numbers[low] + numbers[high];
            if(sum == target) {
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            } else if(sum < target) {
                low++;
            } else {
                high--;
            }
        }
        return ans;
    }
};