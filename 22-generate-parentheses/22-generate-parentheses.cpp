class Solution {
public:
    
    void solve(int open, int close, string s, vector<string> &res) {
        if(open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        
        if(open > 0) {
            solve(open-1, close, s+"(", res);
        }
        if(close > open) {
            solve(open, close-1, s+")", res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = n, close = n;
        solve(open, close, "", res);
        return res;
    }
};