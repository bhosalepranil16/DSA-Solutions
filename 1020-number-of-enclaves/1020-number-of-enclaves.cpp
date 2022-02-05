class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }
        if(visited[i][j] || grid[i][j] != 1) {
            return;
        }
        
        visited[i][j] = true;
        dfs(grid, visited, i-1, j, n, m);
        dfs(grid, visited, i+1, j, n, m);
        dfs(grid, visited, i, j-1, n, m);
        dfs(grid, visited, i, j+1, n, m);
        
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
    
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    dfs(grid, visited, i, j, n, m);
                }
            }
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    res++;
                }
            }
        }
        
        return res;
    }
};