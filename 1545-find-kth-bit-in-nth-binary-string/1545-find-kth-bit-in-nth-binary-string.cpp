class Solution {
public:
    
    string invert(string s) {
        string res = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] == '0') {
                res += '1';
            } else {
                res += '0';
            }
        }
        return res;
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        if(n == 1) {
            return s[k-1];
        }
        for(int i=2;i<=n;i++) {
            string temp = invert(s);
            reverse(temp.begin(), temp.end());
            s = s + "1" + temp;
        }
        return s[k-1];
    }
};