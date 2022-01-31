struct myCmp {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> mp;
        
        
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, myCmp> pq(mp.begin(), mp.end()); 
        
        for(int i=0;i<k;i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};