class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size(), size = INT_MAX;
        
        if(n == 1) {
            return strs[0];
        }
        
        for(int i=0;i<n;i++) {
            int temp = strs[i].length();
            if(temp < size) {
                size = temp;
            }
        }
        
        for(int i=0;i<size;i++) {
            bool flag = true;
            char c;
            for(int j=1;j<n;j++) {
                if(strs[j][i] != strs[j-1][i]) {
                    flag = false;
                    break;
                }
                c = strs[j][i];
            }
            if(flag) {
                res += c;
            } else {
                break;
            }
        }
        return res;
    }
};