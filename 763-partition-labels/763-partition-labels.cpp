class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26), res;
        int n = s.length();
        
        for(int i=0;i<n;i++) {
            last[s[i] - 'a'] = i;
        }
        
        int j = 0, ac = 0;
        
        for(int i=0;i<n;i++) {
            j = max(j, last[s[i] - 'a']);
            if(i == j) {
                res.push_back(i - ac + 1);
                ac = i + 1;
            }
        }
        return res;
    }
};