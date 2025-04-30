class Solution {
public:
    int CountDigits(int n)
    {
        int len = 0;
        while(n>0)
        {
            n /= 10;
            len++;
        }
        return len;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums)
        {
            if(CountDigits(num) % 2 == 0) count++;
        }
        return count;
    }
};