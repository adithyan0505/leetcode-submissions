class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int num : nums) {
            for (int p = 2; p <= sqrt(num); p++) {
                if (num % p == 0) {
                    bool prime = 0;
                    while (num % p == 0) {
                        num /= p;
                        prime = 1;
                    }
                    if (prime)
                        primes.insert(p);
                }
            }
            if (num != 1)
                primes.insert(num);
        }
        return primes.size();
    }
};