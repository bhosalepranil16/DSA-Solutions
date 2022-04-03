class Solution {
public:
    
    void reverse(string& temp) {
        int low = 0, high = temp.length() - 1;
                while(low < high) {
                    swap(temp[low], temp[high]);
                    low++;
                    high--;
                }
    }
    
    string reverseWords(string s) {
        string ans = "", temp = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                reverse(temp);
                if(ans.length() == 0) {
                    ans = ans + temp;
                } else {
                    ans = ans + " " + temp;
                }
                temp = "";
            } else {
                temp = temp + s[i];
            }
        }
        if(temp.length() > 0) {
            reverse(temp);
            if(ans.length() == 0) {
                    ans = ans + temp;
                } else {
                    ans = ans + " " + temp;
                }
        }
        return ans;
    }
};