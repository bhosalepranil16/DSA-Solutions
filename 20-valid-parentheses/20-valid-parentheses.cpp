class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++) {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if(st.empty()) {
                    return false;
                }
                char dh = st.top();
                st.pop();
                if(ch == ')' && dh == '(') {
                    continue;
                } else if(ch == ']' && dh == '[') {
                    continue;
                } else if(ch == '}' && dh == '{') {
                    continue;
                } else {
                    return false;
                }
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};