class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        if(n == 2) {
            return 1;
        }
        vector<int> lDist(n), rDist(n), mDist(n);
        
        int seatedSit = -1;
        for(int i=0;i<n;i++) {
            if(seats[i] == 1) {
                lDist[i] = -1;
                seatedSit = i;
            } else {
                if(seatedSit == -1) {
                    lDist[i] = INT_MAX;
                } else {
                    lDist[i] = i - seatedSit;
                }
            }
        }
        
        seatedSit = -1;
        
        for(int i=n-1;i>=0;i--) {
            if(seats[i] == 1) {
                rDist[i] = -1;
                seatedSit = i;
            } else {
                if(seatedSit == -1) {
                    rDist[i] = INT_MAX;
                } else {
                    rDist[i] = seatedSit - i;
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(seats[i] == 0) {
                mDist[i] = min(lDist[i], rDist[i]);
            } else {
                mDist[i] = INT_MIN;
            }
        }
        
        int maxIndex = 0, maxVal = mDist[0];
        
        for(int i=1;i<n;i++) {
            if(maxVal < mDist[i]) {
                maxVal = mDist[i];
                maxIndex = i;
            }
        }
        
        return maxVal;
    }
};