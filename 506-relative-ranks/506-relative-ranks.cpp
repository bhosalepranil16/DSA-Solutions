class Solution {
public:
    
    static bool sortByScore(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
    
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n, "");
        
        vector<pair<int, int> > arr;
        for(int i=0;i<n;i++) {
            arr.push_back(make_pair(i, score[i]));
        }
        
        sort(arr.begin(), arr.end(), sortByScore);
                
        for(int i=0;i<n;i++) {
            pair<int, int> a = arr[i];
            if(i == 0) {
                res[a.first] = "Gold Medal";
            } else if(i == 1) {
                res[a.first] = "Silver Medal";
            } else if(i == 2) {
                res[a.first] = "Bronze Medal";
            } else {
                res[a.first] = to_string(i+1);
            }
        }
        
        return res;
        
    }
};