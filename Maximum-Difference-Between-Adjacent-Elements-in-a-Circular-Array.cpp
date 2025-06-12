class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for(int i=0;i<n;i++)
        {
            maxVal = max(maxVal,abs(nums[i%n]-nums[(i+1)%n]));
        }
        return maxVal;
    }
};