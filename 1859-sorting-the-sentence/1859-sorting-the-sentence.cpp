class Solution {
public:
    
    static bool myCmp(string &x, string &y) {
        return x[x.length() - 1] < y[y.length() - 1];
    }
    
    string sortSentence(string s) {
        int n = s.length();
        vector<string> arr;
        string temp = "";
        for(int i=0;i<n;i++) {
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
        
        sort(arr.begin(), arr.end(), myCmp);
        
        string res = "" ;
        for(string a : arr) {
            int x = a.length();
            if(res.length() == 0) {
                res = a.substr(0, x-1);
            } else {
                res = res + " " + a.substr(0, x-1);
            }
        }
        return res;
    }
};