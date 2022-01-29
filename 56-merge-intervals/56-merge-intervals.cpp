class Solution {
public:
    
    static bool comapreIntervals(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        stack<vector<int> > st;
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), comapreIntervals);
        st.push(intervals[0]);
        
        for(int i=1;i<n;i++) {
            vector<int> curr = st.top();
            if(curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
                st.pop();
                st.push(curr);
            } else {
                st.push(intervals[i]);
            }
        }
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }        
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};