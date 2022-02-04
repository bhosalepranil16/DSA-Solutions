class Solution {
public:
    
    void dfs(map<int, vector<int> > &mp, vector<bool> &visited, int u) {
        
        visited[u] = true;
        
        for(int v : mp[u]) {
            if(!visited[v]) {
                dfs(mp, visited, v);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) {
            return -1;
        }
        
        map<int, vector<int> > mp;
        
        for(int i=0;i<m;i++) {
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n, false);
        int no = 0;
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(mp, visited, i);
                no++;
            }
        }
        
       int extraCables = m - no - 1;
        
        if(extraCables >= 0) {
            return no - 1;
        } else {
            return -1;
        }
        
    }
};