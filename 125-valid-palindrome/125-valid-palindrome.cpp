class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        int n = s.length();
        
        for(int i=0;i<n;i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                res += s[i] + 32;
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            } else if(s[i] >= '0' && s[i] <= '9') {
                res += s[i];
            }
        }
        
        int low = 0, high = res.length() - 1;
        // cout << res;
        while(low < high) {
            if(res[low] != res[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};