class Solution {
public:
    string simplifyPath(string path) {
        
        string res = "";
        stack<string> st;
        int n = path.length();
        
        for(int i=0;i<n;i++) {
            
            string temp = "";
            
            if(path[i] == '/')  {
                continue;
            }
            
            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            
            if(temp == ".") {
                continue;
            } else if(temp == "..") {
                
                if(!st.empty()) {
                    st.pop();
                }
                
            } else {
                st.push(temp);
            }
            
        }
        
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.length() == 0) {
            return "/";
        }
        
        return res;
        
    }
};