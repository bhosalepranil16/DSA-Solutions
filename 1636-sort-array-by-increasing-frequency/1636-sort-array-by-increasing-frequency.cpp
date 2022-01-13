class Solution {
public:
    
    static bool sortByCount(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int> > arr;
        for(int i=-100;i<=100;i++) {
            arr.push_back(make_pair(i, 0));
        }
        
        for(int i=0; i<nums.size(); i++) {
            arr[nums[i] + 100].second++;
        }
        
        sort(arr.begin(), arr.end(), sortByCount);
        
        vector<int> res;
        
        for(pair<int, int> a : arr) {
            while(a.second > 0) {
                res.push_back(a.first);
                a.second--;
            }
        }
        return res;
    }
};