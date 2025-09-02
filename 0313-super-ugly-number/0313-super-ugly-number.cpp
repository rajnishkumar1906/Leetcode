class Solution {
public:
    struct Compare {
        bool operator()(const pair<long long,int>& a, const pair<long long,int>& b) {
            return a.first > b.first; 
        }
    };

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> ugly(n);
        ugly[0] = 1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, Compare> pq;
        vector<int> idx(primes.size(), 0);

        for (int i = 0; i < primes.size(); i++) {
            pq.push({(long long)primes[i] * ugly[0], i});
        }

        for (int i = 1; i < n; i++) {
            ugly[i] = pq.top().first;

            while (!pq.empty() && pq.top().first == ugly[i]) {
                auto [val, primeIdx] = pq.top();
                pq.pop();
                idx[primeIdx]++;
                pq.push({(long long)primes[primeIdx] * ugly[idx[primeIdx]], primeIdx});
            }
        }

        return (int)ugly[n - 1];
    }
};
