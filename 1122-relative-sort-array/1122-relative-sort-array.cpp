class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr(1001, 0);
        
        int n = arr1.size();
        
        for(int i=0;i<n;i++) {
            arr[arr1[i]]++;
        }
        
        vector<int> res;
        int m = arr2.size();
        
        for(int i=0;i<m;i++) {
            while(arr[arr2[i]] > 0) {
                res.push_back(arr2[i]);
                arr[arr2[i]]--;
            }
        }
        
        for(int i=0;i<1001;i++) {
            while(arr[i]>0) {
                res.push_back(i);
                arr[i]--;
            }
        }
        
        return res;
    }
};