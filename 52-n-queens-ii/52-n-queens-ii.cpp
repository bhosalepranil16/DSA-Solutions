class Solution {
public:    
    bool isSafe(vector<vector<int> > &board, int row, int col, int n) {
        int i, j;
        for(i=0;i<col;i++) {
            if(board[row][i] == 1) {
                return false;
            }
        }
        
        for(i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        
        for(i=row, j=col; i<n && j>=0; i++, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        
        return true;
        
    }
    
    bool solveNQ(vector<vector<int> > &board, int col, int n, int &res) {
        
        if(col == n) {
            res++;
            return true;
        }
        
        bool flag = false;
        
        for(int i=0;i<n;i++) {
            if(isSafe(board, i, col, n)) {
                board[i][col] = 1;
                flag = solveNQ(board, col+1, n, res) || flag;
                board[i][col] = 0;
            }
        }
        
        return flag;
    }
    
    int totalNQueens(int n) {
        vector<vector<int> > board(n, vector<int>(n, 0));
        int res = 0;
        solveNQ(board, 0, n, res);
        return res;
    }
};