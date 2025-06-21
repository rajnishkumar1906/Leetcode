class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for (int i = 0;i<word.size();i++) {
            freq[word[i]-'a']++;
        }

        sort(freq.begin(),freq.end());
        
        int res = INT_MAX;
        int o = 0;

        for (int i = 0;i<26;i++) {
            int c = o;
            int m = freq[i];
            for (int b = i+1;b<26;b++) {

                if (freq[b]-m>k) {
                    c += (freq[b]-m-k);
                }
                
            }

            res = min(res,c);

            o+=freq[i];
        }

        return res;
    }
};