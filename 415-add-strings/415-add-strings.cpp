class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        int carry = 0, i = 0, j = 0;
        int n = num1.length(), m = num2.length();
        while(i < n && j < m) {
            int a = (int) num1[i] - 48, b = (int) num2[j] - 48;
            int sum = a + b + carry;
            carry = sum / 10;
            int rem = sum % 10;
            ans = to_string(rem) + ans;
            // cout << ans << " ";
            i++;
            j++;
        }
        while(i < n) {
            int a = (int) num1[i] - 48;
            int sum = a + carry;
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
            i++;
        }
        while(j < m) {
            int a = (int) num2[j] - 48;
            int sum = a + carry;
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
            j++;
        }
        if(carry>0) {
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};