class Solution {
public:
    
    bool check(unordered_map<char, string> &hash, string s, char c) {
        
        for(pair<char, string> a : hash) {
            if(s == a.second && c != a.first) {
                return false;
            }
        }
        return true;
    }
    
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash;
        int n = pattern.length(), m = s.length();
        vector<string> arr;
        
        string temp = "";
        
        for(int i=0;i<m;i++) {
            if(s[i] == ' ') {
                arr.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        
        if(temp.length() > 0) {
            arr.push_back(temp);
        }
        m = arr.size();
        if(n != m) {
            return false;
        }
        
        for(int i=0;i<n;i++) {
            unordered_map<char, string> :: iterator it = hash.find(pattern[i]);
            
            if(it != hash.end()) {
                if(it->second != arr[i]) {
                    return false;
                }
            } else {
                if(!check(hash, arr[i], pattern[i])) {
                    return false;
                } else {
                    hash[pattern[i]] = arr[i];
                }
            }
            
        }
        
        return true;
    }
};