class Solution {
public:
    
    static bool sortByOrder(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int> > arr;
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            arr.push_back(make_pair(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        vector<pair<int,int> > brr;
        for(int i=0;i<k;i++) {
            brr.push_back(arr[n-1-i]);
        }
        sort(brr.begin(), brr.end(), sortByOrder);
        for(int i=0;i<k;i++) {
            res.push_back(brr[i].first);
        }
        return res;
    }
};