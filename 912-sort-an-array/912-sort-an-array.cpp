class Solution {
public:
    
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    
    void merge(vector<int> &nums, int low, int mid, int high) {
        int n = mid - low + 1, m = high - mid;
        vector<int> arr1, arr2;
        for(int i=low;i<=mid;i++) {
            arr1.push_back(nums[i]);
        }
        for(int i = mid+1;i<=high;i++) {
            arr2.push_back(nums[i]);
        }
        
        int i = 0, j = 0, k = low;
        while(i < n && j < m) {
            if(arr1[i] < arr2[j]) {
                nums[k] = arr1[i];
                i++;
                k++;
            } else {
                nums[k] = arr2[j];
                j++;
                k++;
            }
        }
        
        while(i < n) {
            nums[k] = arr1[i];
            k++;
            i++;
        }
        
        while(j < m) {
            nums[k] = arr2[j];
            k++;
            j++;
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};