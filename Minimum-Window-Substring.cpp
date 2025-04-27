class Solution {
public:
    bool check(const unordered_map<char, int>& window, const unordered_map<char, int>& t_Freq) {  
    for (const auto& [key, val] : t_Freq) 
    {  
        if (window.find(key) == window.end() || window.at(key) < val) 
        {  
            return false;  
        }  
    }  
        return true;  
    }
    string minWindow(string s, string t) {  
        unordered_map<char, int> t_Freq;  
        for (char c : t) {  
            t_Freq[c]++;  
        }  

        unordered_map<char, int> window;  
        int start = 0, end = 0, minLength = INT_MAX; // Changed to INT_MAX  
        int minStart = 0, required = t_Freq.size();  
        int formed = 0;  

        while (end < s.length()) {  
            char c = s[end];  
            window[c]++;  
            if (t_Freq.count(c) && window[c] == t_Freq[c]) {  
                formed++;  
            }  

            while (start <= end && formed == required) {  
                char startChar = s[start];  

                if (end - start + 1 < minLength) {  
                    minLength = end - start + 1;  
                    minStart = start;  
                }  

                window[startChar]--;  
                if (t_Freq.count(startChar) && window[startChar] < t_Freq[startChar]) {  
                    formed--;  
                }  
                start++;  
            }  
            end++;  
        }  

        return minLength == INT_MAX ? \\ : s.substr(minStart, minLength);  
    }    
};