class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int res = -1;
        while(k > 0) {
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};