class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > ans;
        vector<int> a;
        a.push_back(1);
        ans.push_back(a);
        if(rowIndex == 0) {
            return a;
        }
        vector<int> b{1, 1};
        ans.push_back(b);
        if(rowIndex == 1) {
            return b;
        }
        for(int i=2;i<=rowIndex;i++) {
            vector<int> c(i+1, 1);
            for(int j=1;j<c.size()-1;j++) {
                c[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(c);
        }
        return ans[ans.size()-1];
    }
};