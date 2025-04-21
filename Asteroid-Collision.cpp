#include <vector>  
#include <stack>  
#include <cmath>  

class Solution {  
public:  
    void stackToArray(stack<int>& originalStack, vector<int>& array) {  
        stack<int> tempStack;  

        while (!originalStack.empty()) {  
            tempStack.push(originalStack.top());  
            originalStack.pop();  
        }  
        while (!tempStack.empty()) {  
            array.push_back(tempStack.top());  
            tempStack.pop();  
        }  
    }  
    
    vector<int> asteroidCollision(vector<int>& asteroids) {  
        int n = asteroids.size();  
        stack<int> st;  

        for (int i = 0; i < n; i++) {  
            if (st.empty() || (st.top() * asteroids[i] >= 0) || (st.top() < 0 && asteroids[i] > 0)) {  
                st.push(asteroids[i]);  
            } else {  
                int x = asteroids[i];  

                while (x < 0 && !st.empty() && st.top() > 0) {  
                    if (abs(x) > st.top()) {  
                        st.pop();  
                    } else if (abs(x) < st.top()) {  
                        x = 0;  
                    } else {  
                        st.pop();  
                        x = 0;  
                    }  
                }  

                if (x != 0) {  
                    st.push(x);  
                }  
            }  
        }  

        vector<int> Ans;   
        stackToArray(st, Ans);  
        return Ans;  
    }  
};  