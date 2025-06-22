class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int len = 0;
        vector<string>res;
        string temp = "";
        for(int i=0;i<n;i++)
        {
            temp += s[i];
            len++;

            if(len == k)
            {
                res.push_back(temp);
                temp = "";
                len = 0;
            }
        }
        if(len!=0)
        {
            for(int i=len;i<k;i++)
            {
                temp += fill;
            }
            res.push_back(temp);
        }
        return res;
    }
};