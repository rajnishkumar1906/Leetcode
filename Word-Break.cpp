class Solution {  
public:  
    vector<int> dp;  

    bool solve(int i, const string& s, unordered_set<string>& dict) {  
        if (i == s.length()) return true;  
        if (dp[i] != -1) return dp[i];  

        string st = \\;  
        for (int k = i; k < s.length(); k++) {  
            st += s[k];  
            if (dict.find(st) != dict.end()) {  
                if (solve(k + 1, s, dict)) {  
                    dp[i] = true;   
                    return true;  
                }  
            }  
        }  
        dp[i] = false;   
        return false;  
    }  

    bool wordBreak(string s, vector<string>& wordDict) {  
        unordered_set<string> dict(wordDict.begin(), wordDict.end());  
        dp = vector<int>(s.length(), -1);  
        return solve(0, s, dict);  
    }  
};  