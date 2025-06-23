class Solution {
public:
    vector<int> nextSmallerIndex(vector<int>& hist) {
        int n = hist.size();
        vector<int> ans(n, n); // Default to n (right bound)
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && hist[st.top()] >= hist[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmallerIndex(vector<int>& hist) {
        int n = hist.size();
        vector<int> ans(n, -1); // Default to -1 (left bound)
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && hist[st.top()] >= hist[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int maxHistArea(vector<int>& hist) {
        int n = hist.size();
        vector<int> nse = nextSmallerIndex(hist);
        vector<int> pse = previousSmallerIndex(hist);

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = hist[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> hist(c, 0);
        int maxArea = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == '1') {
                    hist[j]++;
                } else {
                    hist[j] = 0;
                }
            }
            maxArea = max(maxArea, maxHistArea(hist));
        }

        return maxArea;
    }
};
