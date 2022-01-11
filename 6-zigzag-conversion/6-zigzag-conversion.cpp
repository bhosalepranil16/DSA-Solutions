class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> arr(numRows, "");
        int n = s.length(), k = 0;
        if(n == 0 || n == 1 || numRows == 1) {
            return s;
        }
        bool isStraight = true;
        for(int i=0;i<n;i++) {
            arr[k] = arr[k] + s[i];
            if(isStraight) {
                k++;
                if(k == numRows) {
                    isStraight = false;
                    k = numRows-2;
                }
            } else if(!isStraight) {
                k--;
                if(k==-1) {
                    isStraight = true;
                    k = 1;
                }
            }
        }
        string res = "";
        for(auto x : arr) {
            res += x;
        }
        return res;
    }
};