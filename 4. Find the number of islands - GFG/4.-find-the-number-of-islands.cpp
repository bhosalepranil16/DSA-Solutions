// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool> > &visited, int i, int j, int n, int m) {
        
        if(visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        // cout << i << " " << j << endl;
        
        if(i - 1 >= 0 && grid[i-1][j] == '1') {
            dfs(grid, visited, i-1, j, n, m);
        }
        
        if(i + 1 < n && grid[i+1][j] == '1') {
            dfs(grid, visited, i+1, j, n, m);
        }
        
        if(j - 1 >= 0 && grid[i][j-1] == '1') {
            dfs(grid, visited, i, j-1, n, m);
        }
        
        if(j + 1 < m && grid[i][j+1] == '1') {
            dfs(grid, visited, i, j+1, n, m);
        }
        
        if(i - 1 >= 0 && j - 1>= 0 && grid[i-1][j-1] == '1') {
            dfs(grid, visited, i-1, j-1, n, m);
        }
        
        if(i - 1 >= 0 && j + 1 < m && grid[i-1][j+1] == '1') {
            dfs(grid, visited, i-1, j+1, n, m);
        }
        
        if(i + 1 < n && j - 1 >= 0 && grid[i+1][j-1] == '1') {
            dfs(grid, visited, i+1, j-1, n, m);
        }
        
        if(i + 1 < n && j + 1 < m && grid[i+1][j+1] == '1') {
            dfs(grid, visited, i+1, j+1, n, m);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        int res = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    res++;
                }
            }
        }
        
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends