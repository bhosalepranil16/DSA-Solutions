class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        
        if(num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        
        
        vector<vector<int> >  arr;
        
        int carry, maxLen = 0;
        
        for(int i=0;i<n;i++) {
            int a = (int) num1[i] - '0';
            vector<int> temp;
            for(int k=0;k<i;k++) {
                temp.push_back(0);
            }
            carry = 0;
            for(int j=0;j<m;j++) {
                int b = (int) num2[j] - '0';
                int total = (a * b) + carry;
                temp.push_back(total % 10);
                carry = total / 10;
            }
            while(carry > 0) {
                temp.push_back(carry % 10);
                carry /= 10;
            }
            arr.push_back(temp);
            int x = temp.size();
            if(x > maxLen) {
                maxLen = x;
            }
            // for(int a : temp) {
            //     cout << a << " ";
            // }
            // cout << endl;
        }
        // cout << maxLen;
        vector<int> temp;
        int sum = 0;
        carry = 0;
        for(int i=0;i<maxLen;i++) {
            sum = 0;
            for(int j=0;j<arr.size();j++) {
                if(i < arr[j].size()) {
                    sum += arr[j][i];
                }
            }
            sum += carry;
            // cout << sum << " " << carry << endl;
            temp.push_back(sum % 10);
            carry = sum / 10;
        }
        
        while(carry > 0) {
            temp.push_back(carry % 10);
            carry = carry / 10;
        }
        
        string res = "";
        
        for(int i=0;i<temp.size();i++) {
            res += (char) temp[i] + '0';
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};