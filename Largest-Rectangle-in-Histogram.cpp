class Solution {
public:
    // Index of next smaller elements
    vector<int> nextSmallerElements(vector<int>& heights)
    {
        int n = heights.size();
        vector<int>Ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                Ans[i] = st.top();
            }
            st.push(i);
        }
        return Ans;
    }
    // Index of previous smaller elements
    vector<int> previousSmallerElements(vector<int>& heights)
    {
        int n = heights.size();
        vector<int>Ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                Ans[i] = st.top();
            }
            st.push(i);
        }
        return Ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        long long maxArea = 0;
        int n = heights.size();
        vector<int>next = nextSmallerElements(heights);
        vector<int>prev = previousSmallerElements(heights);

        for(int i=0;i<n;i++)
        {
            // Finding the width of the rectangle
            int right = next[i] == -1 ? n : next[i];
            int left = prev[i] == -1 ? 0 : prev[i] + 1;   // (-1) + 1 = 0
            long long area = (right - left) * heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
}; 