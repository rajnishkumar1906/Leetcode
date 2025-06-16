class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>PrefixMin(n,nums[0]);
        vector<int>SuffixMax(n,nums[n-1]);
        for(int i=1;i<n;i++)
        {
            PrefixMin[i] = min(PrefixMin[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            SuffixMax[i] = max(SuffixMax[i+1],nums[i]);
        }

        int maxDiff = INT_MIN;
        for(int i=0;i<n;i++)
        {
            
            maxDiff = max(maxDiff,abs(SuffixMax[i] - PrefixMin[i]));
        }
        if(maxDiff == 0 ) return -1;
        return maxDiff;
    }
};