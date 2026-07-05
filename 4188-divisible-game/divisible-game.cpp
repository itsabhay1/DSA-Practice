class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const int MOD = 1e9+7;
        set<int>primes;

        for(int x: nums){
            int temp = x;

            if(temp%2 == 0){
                primes.insert(2);
                while(temp%2 == 0){
                    temp /= 2;
                }
            }

            for(int d =3; d*d <=temp; d += 2){
                if(temp % d == 0){
                    primes.insert(d);
                    while(temp%d == 0){
                        temp /= d;
                    }
                }
            }

            if(temp > 1){
                primes.insert(temp);
            }
        }

        if(primes.empty()){
            int k = 2;
            long long maxDiff = -1;
            return ((maxDiff*k)%MOD + MOD) % MOD;
        }

        long long maxDiff = INT_MIN;
        int k = 0;

        for(int p: primes){
            long long currMax = INT_MIN;
            long long currSum = 0;
            for(int n: nums){
                long long val = (n % p == 0) ? n : -n;
                currSum = max(val, currSum+val);
                currMax = max(currSum, currMax);
            }

            if(currMax > maxDiff){
                maxDiff = currMax;
                k = p;
            }
        }

        return (maxDiff % MOD) * (k % MOD) % MOD;
    }
};