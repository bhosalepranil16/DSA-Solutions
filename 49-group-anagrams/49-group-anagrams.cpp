class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<pair<string, int> > arr;
        vector<vector<string> > res;
        unordered_map<string, vector<string> > temp;
        int n = strs.size();
        
        for(int i=0;i<n;i++) {
            arr.push_back(make_pair(strs[i], i));
            sort(arr[i].first.begin(), arr[i].first.end());
        }
        
        for(int i=0;i<n;i++) {
            // cout << arr[i].first << " " << strs[arr[i].second] <<endl;
            temp[arr[i].first].push_back(strs[arr[i].second]);
        }
        
        for(pair<string, vector<string> > a : temp) {
            res.push_back(a.second);
        }
        
        return res;
    }
};