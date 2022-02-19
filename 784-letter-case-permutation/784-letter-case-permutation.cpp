class Solution {
public:
    
    void solve(string ip, string op, vector<string> &res, int i, int n) {
        if(i == n) {
            res.push_back(op);
            return;
        }
        if(ip[i] >= '0' && ip[i] <= '9') {
            solve(ip, op + ip[i], res, i+1, n);
            return;
        }
        
        if(ip[i] >= 'a' && ip[i] <= 'z') {
            char s = ip[i];
            char c = toupper(s);
            solve(ip, op+c, res, i+1, n);
            solve(ip, op+s, res, i+1, n);
        } else {
            char c = ip[i];
            char s = tolower(c);
            solve(ip, op+c, res, i+1, n);
            solve(ip, op+s, res, i+1, n);            
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s, "", res, 0, s.length());
        return res;
    }
};