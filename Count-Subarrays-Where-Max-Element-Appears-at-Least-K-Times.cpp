class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxValue = nums[0];
        long long Subarrays = 0;
        for(int i=1;i<n;i++)
        {
            maxValue = max(maxValue,nums[i]);
        }

        long long start = 0;
        // Count of maxValue in a window or subarray
        long long count = 0;      
        for(int end=0;end<n;end++)
        {
            if(nums[end]==maxValue) count++;

            while(count>=k)
            {
                if(nums[start]==maxValue)
                {
                    count--;
                }
                start++;
            }
            Subarrays+=start;
        }
        return Subarrays;
    }
};