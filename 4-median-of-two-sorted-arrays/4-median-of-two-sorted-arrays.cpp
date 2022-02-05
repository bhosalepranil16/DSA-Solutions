class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < n) {
            arr.push_back(nums1[i]);
            i++;
        }
        
        while(j < m) {
            arr.push_back(nums2[j]);
            j++;
        }
        
        int N = n + m;
        double res;
        if(N % 2 == 1) {
            res = (double) arr[N/2];
        } else {
            res = (double) (arr[N/2] + arr[N/2 - 1])/2;
        }
        return res;
    }
};