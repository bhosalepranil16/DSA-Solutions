class Solution {
public:
    # define mod 1000000007
    int countOrders(int n) {
        if(n == 0) {
            return 1;
        }
        long long ans = (long long) n * (2*n - 1) % mod;
        ans = ans * countOrders(n-1) % mod;
        return (int) ans;
    }
};