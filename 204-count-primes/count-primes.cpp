class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes;
        vector<bool>isPrime(n,true);
        if(n<=2) return 0;
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i<n; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }

            for(int p: primes){
                if(i*p>=n) break;
                isPrime[i*p] = false;
                if(p%i == 0)break;
            }
        }
        return primes.size();
    }
};