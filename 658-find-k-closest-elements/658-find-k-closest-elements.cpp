struct myCmp {
    bool operator()(pair<int, int> const& a, pair<int, int> const &b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, myCmp> pq;
        
        for(int i=0;i<n;i++) {
            pq.push(make_pair(abs(arr[i] - x), arr[i]));
        }
        
        vector<int> res;
        for(int i=0;i<k;i++) {
            pair<int, int> curr = pq.top();
            cout << curr.first << " " << curr.second << endl;
            pq.pop();
            res.push_back(curr.second);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};