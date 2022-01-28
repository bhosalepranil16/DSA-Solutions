class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n), rmax(n);
        
        int a = height[0];
        for(int i=0;i<n;i++) {
            a = max(a, height[i]);
            lmax[i] = a;
        }
        
        a = height[n-1];
        for(int i=n-1;i>=0;i--) {
            a = max(a, height[i]);
            rmax[i] = a;
        }
        
        int res = 0;
        
        for(int i=1;i<n-1;i++) {
            res += min(lmax[i], rmax[i]) - height[i];
        }
        
        return res;
    }
};