class Solution {
public:
    vector<int> t;
    
    Solution() {
        t = vector<int>(10001, -1);
    }
    
    int getMaxPoints(vector<int> &arr, int id) {
        
        if(id > 10000) {
            return 0;
        }
        
        if(t[id] == -1) {
            t[id] = max(arr[id] * id + getMaxPoints(arr, id+2), getMaxPoints(arr, id+1));
        }
        
        return t[id];
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001, 0);
        
        for(int i : nums) {
            arr[i]++;
        }
        
        return getMaxPoints(arr, 0);
        
    }
};