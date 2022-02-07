class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = 0;
        int low = 0, high = height.size() - 1;
        
        while(low < high) {
            int h = min(height[low], height[high]);
            res = max(res, h * (high - low));
            
            while(height[low] <= h && low < high) {
                low++;
            }
            
            while(height[high] <= h && low < high) {
                high--;
            }
        }
        return res;
    }
};