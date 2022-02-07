struct myCmp {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq(mp.begin(), mp.end());
        
        int res = 0;
        int count = 0;
        while(count < n/2) {
            pair<int, int> a = pq.top();
            pq.pop();
            
            count += a.second;
            res++;
        }
        
        return res;
    }
};