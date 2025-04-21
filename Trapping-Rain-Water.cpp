class Solution {
public:
    vector<int> prefixMax(vector<int>& height) {
        int n = height.size();
        vector<int> PrfxMax(n, 0);
        PrfxMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            PrfxMax[i] = max(PrfxMax[i - 1], height[i]);
        }
        return PrfxMax;
    }

    vector<int> suffixMax(vector<int>& height) {
        int n = height.size();  
        vector<int> SufxMax(n, 0);
        SufxMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            SufxMax[i] = max(SufxMax[i + 1], height[i]);  
        }
        return SufxMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();  
        if (n < 3) return 0;

        vector<int> leftMax = prefixMax(height);
        vector<int> rightMax = suffixMax(height);

        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }
        return waterTrapped;
    }
};
