class Solution {
public:
    
    bool isPalindrome(string &s, int low, int high) {
        if(low > high) {
            return false;
        }
        while(low < high) {
            if(s[low] != s[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    
    void partitionUtil(string &s, int start, vector<string> &arr, vector<vector<string> > &res) {
        if(start >= s.length()) {
            res.push_back(arr);
            return;
        }
        
        for(int i=start; i<s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                arr.push_back(s.substr(start, i - start + 1));
                partitionUtil(s, i+1, arr, res);
                arr.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> arr;
        partitionUtil(s, 0, arr, res);
        return res;
    }
};