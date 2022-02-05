class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> dist(n+1, INT_MAX);
        map<int, vector<pair<int, int>>> mp;
        vector<bool> visited(n+1, false);
        
        for(int i=0;i<times.size();i++) {
            mp[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        dist[k] = 0;
        
        for(int i=1;i<=n;i++) {
            
            int u = -1;
            
            for(int j=1;j<=n;j++) {
                if(!visited[j] && (u == -1 || dist[u] > dist[j])) {
                    u = j;
                }
            }
            
            visited[u] = true;
            
            for(pair<int, int> v : mp[u]) {
                if(!visited[v.first] && dist[u] != INT_MAX) {
                    dist[v.first] = min(dist[v.first], dist[u] + v.second); 
                }
            }
        }
        
        int res = INT_MIN;
        
        for(int i=1;i<=n;i++) {
            res = max(res, dist[i]);
        }
        
        if(res == INT_MAX) {
            return -1;
        } else {
            return res;
        }
    }
};