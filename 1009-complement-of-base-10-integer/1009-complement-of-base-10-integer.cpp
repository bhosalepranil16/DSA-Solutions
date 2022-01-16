class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        int res = 0, i = 0;
        while(n > 0) {
            int rem = n % 2;
            if(rem == 0) {
                res += pow(2, i);
            }
            i++;
            n = n / 2;
        }
        return res;
    }
};