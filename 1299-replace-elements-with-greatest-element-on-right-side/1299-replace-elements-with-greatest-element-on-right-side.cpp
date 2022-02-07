class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n ,-1);
        int temp = arr[n-1];
        for(int i=n-2;i>=0;i--) {
            res[i] = temp;
            temp = max(temp, arr[i]);
        }
        return res;
    }
};