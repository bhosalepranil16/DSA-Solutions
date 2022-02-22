class Solution {
public:
    
    bool findEmptyCell(vector<vector<char>>& board, int &row, int &col) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') {
                    row = i;
                    col = j;
                    return false;
                } 
            }
        }
        return true;
    }
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        
        for(int i=0;i<9;i++) {
            if(board[row][i] == num) {
                return false;
            }
            if(board[i][col] == num) {
                return false;
            }
        }
        
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i+startRow][j+startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        
        int row, col;
        
        if(findEmptyCell(board, row, col)) {
            return true;
        }
        
        for(int i=1;i<=9;i++) {
            
            char num = (char) i + 48;
            
            if(isSafe(board, row, col, num)) {
                board[row][col] = num;
                if(solve(board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};