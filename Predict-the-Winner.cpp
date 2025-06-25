class Solution {
public:
    // bool A says if A's turn'
    bool isAwinner(vector<int>&nums,bool A,int left,int right,int s1,int s2)
    {
        if(left>right) return (s1 >= s2);

        // It's A's turn
        if(A)
        {
            bool leftPick = isAwinner(nums,false,left+1,right,s1+nums[left],s2);
            bool rightPick = isAwinner(nums,false,left,right-1,s1+nums[right],s2);
            return leftPick || rightPick;
        }
        else
        {
            bool leftPick = isAwinner(nums,true,left+1,right,s1,s2+nums[left]);
            bool rightPick = isAwinner(nums,true,left,right-1,s1,s2+nums[right]);
            return leftPick && rightPick;
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int left = 0 ,right = n-1;
        return isAwinner(nums,true,left,right,0,0);
    }
};