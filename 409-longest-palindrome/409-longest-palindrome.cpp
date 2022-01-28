class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> temp(52, 0);
        int n = s.length();
        for(int i=0;i<n;i++) {
            char c = s[i];
            if(c >= 65 && c <= 90) {
                temp[c-65]++;
            } else if(c >= 97 && c<= 122) {
                temp[c-97+26]++;
            }
        }
        int flag = false, res = 0;
        for(int i=0;i<52;i++) {
            // cout << temp[i] << " ";
            if(temp[i] % 2 == 0) {
                res += temp[i];
            } else {
                flag = true;
                res += (temp[i] - 1);
            }
        }
        
        if(flag)
            return res + 1;
        else
            return res;
    }
};