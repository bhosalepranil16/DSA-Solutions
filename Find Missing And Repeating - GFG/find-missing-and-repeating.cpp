// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res = new int[2];
        vector<int> temp(n, 0);
        for(int i=0;i<n;i++) {
            temp[arr[i] - 1]++;
        }
        bool flag1 = false, flag2 = false;
        for(int i=0;i<n;i++) {
            if(temp[i] == 0) {
                res[1] = i + 1;
                flag1 = true;
            }
            if(temp[i] == 2) {
                res[0] = i + 1;
                flag2 = true;
            }
            if(flag1 && flag2) {
                break;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends