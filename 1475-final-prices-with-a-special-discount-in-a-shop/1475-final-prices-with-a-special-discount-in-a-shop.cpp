class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        stack<int> st;
        int n = prices.size();
        
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && prices[i] < st.top()) {
                st.pop();
            }
            
            if(st.empty()) {
                res.push_back(prices[i]);
            } else {
                res.push_back(prices[i] - st.top());
            }
            
            st.push(prices[i]);
            
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};