class Solution {  
public:  
    bool isStringPresent(vector<string>& wordDict, string& str) {  
        return find(wordDict.begin(), wordDict.end(), str) != wordDict.end();  
    }  
    
    void solve(int index, string& s, vector<string>& wordDict,vector<string>& Answer, string temp) {  
        if (index == s.length()) {  
            Answer.push_back(temp);  
            return;  
        }  

        string str = "";
        for (int i = index; i < s.length(); i++) {  
            str += s[i];   
            if (isStringPresent(wordDict, str)) {  
                string newTemp = temp.empty() ? str : temp + \ \ + str;  
                solve(i + 1, s, wordDict, Answer, newTemp);  
            }  
        }  
    }  
    
    vector<string> wordBreak(string& s, vector<string>& wordDict) {  
        vector<string> Answer;  
        solve(0, s, wordDict, Answer, \\);   
        return Answer;  
    }  
};  
