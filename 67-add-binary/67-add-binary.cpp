class Solution {
public:
    
    vector<char> add(char x, char y, char carry) {
        vector<char> res(2);
        if(x == '0' && y == '0' && carry == '0') {
            res[0] = '0';
            res[1] = '0';
        } else if(x == '0' && y == '0' && carry == '1') {
            res[0] = '1';
            res[1] = '0';
        } else if(x == '0' && y == '1' && carry == '0') {
            res[0] = '1';
            res[1] = '0';
        } else if(x == '0' && y == '1' && carry == '1') {
            res[0] = '0';
            res[1] = '1';
        } else if(x == '1' && y == '0' && carry == '0') {
            res[0] = '1';
            res[1] = '0';
        } else if(x == '1' && y == '0' && carry == '1') {
            res[0] = '0';
            res[1] = '1';
        } else if(x == '1' && y == '1' && carry == '0') {
            res[0] = '0';
            res[1] = '1';
        } else if(x == '1' && y == '1' && carry == '1') {
            res[0] = '1';
            res[1] = '1';
        }
        return res;
    }
    
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.length(), m = b.length(), i = 0, j = 0;
        string res = "";
        char carry = '0';
        
        while(i < n && j < m) {
            vector<char> arr = add(a[i], b[j], carry);
            res = arr[0] + res;
            carry = arr[1];
            i++;
            j++;
        }
        
        while(i < n) {
            vector<char> arr = add(a[i], '0', carry);
            res = arr[0] + res;
            carry = arr[1];
            i++;
        }
        
        while(j < m) {
            vector<char> arr = add('0', b[j], carry);
            res = arr[0] + res;
            carry = arr[1];
            j++;
        }
        if(carry == '1') {
            res = carry + res;
        }
        return res;
        
    }
};