class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int >FreqMap;
        for(char ch : word)
        {
            FreqMap[ch]++;
        }

        vector<int>Freq;
        for(auto& data: FreqMap)
        {
            Freq.push_back(data.second);
        } 

        int n = Freq.size();
        // sort the Freq vector
        sort(Freq.begin(),Freq.end());

        int minDeletion = INT_MAX;

        int tempDeletion = 0; //Deletion till a chosen index
        for(int i=0;i<n;i++)
        {
            int current = Freq[i];
            int deletion = tempDeletion;
            for(int j=i+1;j<n;j++)
            {
                if(Freq[j] - current > k)
                {
                    deletion += (Freq[j] - current - k); 
                }
            }
            minDeletion  = min(minDeletion , deletion);

            tempDeletion += current;
        }

        return minDeletion;
    }
};