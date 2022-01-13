class Solution {
public:
    
    static bool sortByCount(const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        int n = s.length();
        vector<pair<char, int> > arr;
        for(int i=0;i<26;i++) {
            char c = (char) i + 97;  
            arr.push_back(make_pair(c, 0));
        }
        
        for(int i=0;i<26;i++) {
            char c = (char) i + 65;  
            arr.push_back(make_pair(c, 0));
        }
        
        for(int i=0;i<10;i++) {
            char c = (char) i + 48;
            arr.push_back(make_pair(c, 0));
        }
        
        for(int i=0;i<n;i++) {
            int ind = (int) s[i];
            if(ind >= 97 && ind <= 122) {
                arr[ind - 97].second++;
            } else if(ind >= 65 && ind <= 90) {
                arr[ind - 65 + 26].second++;
            } else if(ind >= 48 && ind <= 57) {
                arr[ind - 48 + 52].second++;
            }
        }
        
        sort(arr.begin(), arr.end(), sortByCount);
        
        string res = "";
        
        for(pair<char, int> a : arr) {
            cout << a.first << " " << a.second << "\n";
            while(a.second > 0) {
                res += a.first;
                a.second--;
            }
        }
        
        return res;
    }
};