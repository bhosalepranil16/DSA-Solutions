class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<int> st;
        int n = temperatures.size();
        
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                res.push_back(0);
            } else {
                res.push_back(st.top() - i);
            }
            st.push(i);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};