class Solution {
public:
    bool isSubsequence(string s, string txt) {
        int m = s.length(), n = txt.length(); 
        int i = 0, j = 0;
        for(i=0;i<n;i++) {
            if(txt[i] == s[j]) {
                j++;
            }
        }
        
        return j == m;
    }
};