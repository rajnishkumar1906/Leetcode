class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(nums[mid] > nums[right])
            {
                left = mid +1;
            }
            else
            {
                right = mid;
            }
        }
        // At the end left==right
        return nums[left];
    }
};