class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0] = 1;
        int p2=0,p3=0,p5=0;
        int next2 = 2, next3 = 3, next5 = 5;
        for(int i=1;i<n;i++)
        {
            int next = min({next2,next3,next5});
            ugly[i] = next;

            if(next == next2) next2 = ugly[++p2]*2;   //next multiple of 2
            if(next == next3) next3 = ugly[++p3]*3;
            if(next == next5) next5 = ugly[++p5]*5;
        }
        return ugly[n-1];
    }
};