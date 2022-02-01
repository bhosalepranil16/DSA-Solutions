class Solution {
public:
    
    void dfs(map<int, vector<int> > &mp, vector<bool> &visited, int src) {
        
        if(visited[src]) {
            return;
        }
        
        visited[src] = true;
        
        for(int v : mp[src]) {
            if(!visited[v]) {
                dfs(mp, visited, v);
            }
        }
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        map<int, vector<int> > mp;
        
        for(int i=0;i<edges.size();i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(mp, visited, source);
        
        return visited[destination];
        
    }
};