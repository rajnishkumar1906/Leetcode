class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>NGE(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && nums[i%n]>=st.top())
            {
                st.pop();
            }
            if(i<n)
            {   
                if(!st.empty())
                {
                    NGE[i%n] = st.top();
                }
                else
                {
                    NGE[i%n] = -1;
                }
            }
            st.push(nums[i%n]);
        }
        return NGE;
    }
};