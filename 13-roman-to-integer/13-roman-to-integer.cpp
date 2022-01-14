class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int res = 0;
        int n = s.length();
        int i = 0;
        while(i<n) {
            char c = s[i];
            if(c == 'V' || c == 'L' || c == 'D' || c == 'M') {
                res += hash[c];
                i++;
            } else if(c == 'I') {
                if(i+1 < n && s[i+1] == 'V') {
                    res += 4;
                    i += 2;
                } else if(i+1 < n && s[i+1] == 'X') {
                    res += 9;
                    i += 2;
                } else {
                    res += 1;
                    i++;
                }
            } else if(c == 'X') {
                if(i+1 < n && s[i+1] == 'L') {
                    res += 40;
                    i += 2;
                } else if(i+1 < n && s[i+1] == 'C') {
                    res += 90;
                    i += 2;
                } else {
                    res += 10;
                    i++;
                }
            } else if(c == 'C') {
                if(i+1 < n && s[i+1] == 'D') {
                    res += 400;
                    i += 2;
                } else if(i+1 < n && s[i+1] == 'M') {
                    res += 900;
                    i += 2;
                } else {
                    res += 100;
                    i++;
                }
            }
        }
        
        return res;
        
    }
};