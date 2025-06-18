// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>PrefixSum(n+1,0);
//         for(int i=1;i<n+1;i++)
//         {
//             PrefixSum[i] = PrefixSum[i-1] + nums[i-1];
//         }

//         int maxSum = INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 int sum = PrefixSum[j+1] - PrefixSum[i];
//                 maxSum = max(sum,maxSum);
//             }
//         }
//         return maxSum;
//     }
// };


// Optimized:
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int n  = nums.size();
//         if(n == 0) return 0;
//         int maxSum = nums[0];
//         int currentSum = nums[0];
//         for(int i=1;i<n;i++)
//         {
//             currentSum = max(nums[i],currentSum + nums[i]);
//             maxSum = max(maxSum,currentSum);
//         }
//         return maxSum;
//     }
// };

class Solution{
    public:
    int maxSubArray(vector<int>&nums)
    {
        int n = nums.size(),ans = INT_MIN , max_start = 0;
        for(int i=0;i<n;i++)
        {
            max_start = max({nums[i],max_start + nums[i]});
            ans = max(ans,max_start);
        }
        return ans;
    }
};