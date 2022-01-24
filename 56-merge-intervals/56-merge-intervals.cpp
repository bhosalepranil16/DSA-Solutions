bool myCmp(vector<int> a1, vector<int> a2) {
    return a1[0] < a2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), myCmp);
        
        stack<vector<int> > s;
        s.push(intervals[0]);
        
        for(int i=1;i<intervals.size(); i++) {
            vector<int> curr = s.top();
            
            if(curr[1] < intervals[i][0]) {
                s.push(intervals[i]);
            }
            else if(curr[1] < intervals[i][1]) {
                curr[1] = intervals[i][1];
                s.pop();
                s.push(curr);
            } 
        }
        vector<vector<int> > ans;
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};