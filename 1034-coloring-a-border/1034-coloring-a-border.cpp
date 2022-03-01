class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& res, vector<vector<bool>>& visited, int i, int j, int m, int n, int prevColor, int color) {
        
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != prevColor) {
            return true;
        }
        
        if(visited[i][j]) {
            return false;
        }
        
        visited[i][j] = true;
        
        
        bool flag1 = dfs(grid, res, visited, i-1, j, m, n, prevColor, color);
        bool flag2 = dfs(grid, res, visited, i+1, j, m, n, prevColor, color);
        bool flag3 = dfs(grid, res, visited, i, j-1, m, n, prevColor, color);
        bool flag4 = dfs(grid, res, visited, i, j+1, m, n, prevColor, color);
        
        bool flag = flag1 || flag2 || flag3 || flag4;
        if(flag) {
            res[i][j] = color;
            return false;
        }
        return false;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<vector<int> > res = grid;
        dfs(grid, res, visited, row, col, m, n, grid[row][col], color);
        return res;
    }
};