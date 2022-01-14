class Solution {
public:
    int addDigits(int num) {
        if(num >= 0 && num <= 9) {
            return num;
        }
        while(true) {
            int res = 0;
            while(num > 0) {
                res += num % 10;
                num = num / 10;
            }
            num = res;
            if(num >= 0 && num <= 9) {
                return num;
            }
        }
        return 0;
    }
};