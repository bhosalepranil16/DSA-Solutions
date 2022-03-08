class Solution {
public:
    
    static bool myCmp(string a, string b) {
        
        string m = a + b, n = b + a;
        
        return m > n;
        
    }
    
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> arr;
        
        for(int i=0;i<n;i++) {
            arr.push_back(to_string(nums[i]));
        }
        
        sort(arr.begin(), arr.end(), myCmp);
        
        if(arr[0] == "0") {
            return "0";
        }
        
        string res = "";
        
        for(int i=0;i<n;i++) {
            res += arr[i];
        }
        
        return res;
    }
};