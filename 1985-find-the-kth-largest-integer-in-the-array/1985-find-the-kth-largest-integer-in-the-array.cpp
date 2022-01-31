struct myCmp {
    bool operator()(string const& s1, string const& s2) {
        int len1 = s1.length(), len2 = s2.length();
        if(len1 == len2) {
            if(s1 == s2) {
                return true;
            } else {
                for(int i=0;i<len1;i++) {
                    if(s1[i] != s2[i]) {
                        return s1[i] < s2[i];
                    }
                }
            }
        }
        return len1 < len2;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, myCmp> pq(nums.begin(), nums.end());
        string res;
        for(int i=0;i<k;i++) {
            res = pq.top();
            // cout << res << "\n";
            pq.pop();
        }
        return res;
    }
};