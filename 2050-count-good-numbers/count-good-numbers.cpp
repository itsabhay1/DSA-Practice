class Solution {
public:
    long long mod = 1e9 + 7;
    int power(long long a, long long b){
        if(b == 0) return 1;
        long long result = power(a,b/2);
        result = (result * result) % mod;
        if(b%2 == 1) result = (result*a) % mod;
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)power(5, (n+1)/2) * power(4,n/2) %mod;
    }
};