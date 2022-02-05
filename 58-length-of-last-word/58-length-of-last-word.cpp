class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, count = 0;
        
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                if(count > 0) {
                    res = count;
                }
                count = 0;
            } else {
                count++;
            }
        }
        
        if(count > 0) {
            res = count;
        }
        
        return res;
    }
};