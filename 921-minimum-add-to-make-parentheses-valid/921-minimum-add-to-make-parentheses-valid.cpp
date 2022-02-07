class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        stack<char> st;
        for(char c : s) {
            if(c == '(') {
                st.push(c);
            } else {
                if(st.empty()) {
                    res++;
                } else {
                    st.pop();
                }
            }
        }
        
        res += st.size();
        return res;
    }
};