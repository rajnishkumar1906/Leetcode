class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        if(s.length()<p.length()) return {};
        vector<int>window(26,0);
        vector<int>freqMap_of_p(26,0);
        vector<int>result;
        for(int i=0;i<p.length();i++)
        {
            window[s[i]-'a']++;
            freqMap_of_p[p[i]-'a']++;
        }
        if(window == freqMap_of_p) result.push_back(0);

        for(int i=p.length();i<s.length();i++)
        {
            window[s[i-p.length()]-'a']--;
            window[s[i]-'a']++;
            if(window == freqMap_of_p) 
            {
                result.push_back(i-p.length()+1);
            }
        }
        return result;
    }
};