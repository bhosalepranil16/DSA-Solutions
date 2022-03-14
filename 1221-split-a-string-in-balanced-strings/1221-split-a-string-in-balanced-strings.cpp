class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, n = s.length(), cnt = 0;
        
        for(int i=0;i<n;i++) {
            if(s[i] == 'L') {
                cnt++;
            } else {
                cnt--;
            }
            
            if(cnt == 0) {
                res++;
            }
        }
        return res;
    }
};