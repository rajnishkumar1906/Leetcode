#include <vector>  
#include <stack>  
#include <unordered_map>  

using namespace std;  

class Solution {  
public:  
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {  
        int n = nums1.size();  
        vector<int> ans(n, -1);  
        stack<int> st;  
        unordered_map<int, int> greaterMap;  
        
        for (int i = nums2.size() - 1; i >= 0; i--) {  
            while (!st.empty() && st.top() <= nums2[i]) {  
                st.pop();  
            }  
            if (!st.empty()) {  
                greaterMap[nums2[i]] = st.top();  
            }  
            st.push(nums2[i]);  
        }  

        for (int i = 0; i < n; i++) {  
            if (greaterMap.find(nums1[i]) != greaterMap.end()) {  
                ans[i] = greaterMap[nums1[i]];  
            }  
        }  

        return ans;  
    }  
};  