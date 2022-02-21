// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
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
        
        for(i=row, j=col; i<n && j >=0; i++, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        
        return true;
    }

    bool solveNQ(vector<vector<int> > &board, int col, int n, vector<vector<int> > &res) {
        
        if(col == n) {
            vector<int> temp;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(board[j][i] == 1) {
                        temp.push_back(j+1);
                        // cout << j + 1 << " ";
                    }
                }
            }
            // cout << endl;
            res.push_back(temp);
            return true;
        }
        bool temp = false;
        for(int i=0;i<n;i++) {
            if(isSafe(board, i, col, n)) {
                board[i][col] = 1;
                temp = solveNQ(board, col+1, n, res) || temp;
                board[i][col] = 0;
            }
        }
        return temp;
    }
    

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int> > res, board(n, vector<int>(n, 0));
        bool flag = solveNQ(board, 0, n, res);
        // cout << flag;
        if(flag) {
            return res;
        } else {
            return {}; 
        } 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends