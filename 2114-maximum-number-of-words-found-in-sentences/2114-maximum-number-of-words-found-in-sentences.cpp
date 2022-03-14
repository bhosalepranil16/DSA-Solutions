class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = INT_MIN;
        for(string a : sentences) {
            int cnt = 0;
            for(int i=0;i<a.length();i++) {
                if(a[i] == ' ') {
                    cnt++;
                }
            }
            res = max(res, cnt+1);
        }
        return res;
    }
};