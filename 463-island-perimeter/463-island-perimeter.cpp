class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int row, int col, int &res) {
        
        if(i < 0 || i >= row || j < 0 || j >= col) {
            res++;
            return;
        }
        
        if(grid[i][j] == 0) {
            res++;
            return;
        }
        
        if(visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        
        dfs(grid, visited, i-1, j, row, col, res);
        dfs(grid, visited, i+1, j, row, col, res);
        dfs(grid, visited, i, j-1, row, col, res);
        dfs(grid, visited, i, j+1, row, col, res);
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j, row, col, res);
                    break;
                }
            }
        }
        return res;
    }
};