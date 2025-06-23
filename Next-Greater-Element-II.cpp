class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,-1);
        // Monotinic stack where lowest is at the top
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && nums[i%n]>=st.top()) st.pop();
            if(!st.empty() && i<n)
            {
                nge[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};