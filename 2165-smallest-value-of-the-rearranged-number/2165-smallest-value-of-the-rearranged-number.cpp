class Solution {
public:
    long long smallestNumber(long long num) {
        
        vector<int> arr;
        bool isNegative = false;
        if(num < 0) {
            isNegative = true;
            num = abs(num);
        }
        
        if(num == 0) {
            return 0;
        }
        
        while(num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }
        
        long long res = 0;
        int n = arr.size();
        
        if(isNegative) {
            sort(arr.begin(), arr.end(), greater<int>());
            
            for(int i=0;i<n;i++) {
                res = res * 10 + arr[i];
            }
            
        } else {
            sort(arr.begin(), arr.end());
            int cnt = 0, i = 0;
            while(arr[i] == 0 && i < n) {
                cnt++;
                i++;
            }
            
            while(i < n) {
                res = res * 10 + arr[i];
                while(cnt > 0) {
                    res = res * 10;
                    cnt--;
                }
                i++;
            }
        }
        
        return isNegative ? -1 * res : res;
        
    }
};