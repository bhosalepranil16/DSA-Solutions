class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            unordered_map<int, int>::iterator itr = mp.find(target - nums[i]);
            if(itr != mp.end()) {
                ans.push_back(i);
                ans.push_back(itr->second);
                return ans;
            } else {
                mp.insert(make_pair(nums[i], i));
            }
        }
        return ans;
    }
};