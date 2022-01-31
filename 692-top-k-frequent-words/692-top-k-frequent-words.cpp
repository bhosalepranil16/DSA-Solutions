struct myCmp {
    bool operator()(pair<string, int> const& a, pair<string, int> const& b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        int n = words.size();
        vector<string> res;
        
        for(int i=0;i<n;i++) {
            mp[words[i]]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int> >, myCmp> pq(mp.begin(), mp.end());
        
        for(int i=0;i<k;i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};