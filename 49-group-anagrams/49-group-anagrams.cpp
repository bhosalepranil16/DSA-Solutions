class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string> > res;
        unordered_map<string, vector<string> > temp;
        int n = strs.size();
        
        for(int i=0;i<n;i++) {
            string x = strs[i];
            sort(x.begin(), x.end());
            temp[x].push_back(strs[i]);
        }
        
        for(pair<string, vector<string> > a : temp) {
            res.push_back(a.second);
        }
        
        return res;
    }
};