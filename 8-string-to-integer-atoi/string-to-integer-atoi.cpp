class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return helper(s, i, 0, sign);
    }

private:
    int helper(string& s, int i, long long ans, int sign) {
        if (i > s.length() || s[i] < '0' || s[i] > '9') {
            ans *= sign;
            if (ans > INT_MAX)
                return INT_MAX;
            if (ans < INT_MIN)
                return INT_MIN;
            return (int)ans;
        }

        int digit = s[i] - '0';
        if (ans > (LLONG_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        return helper(s, i + 1, ans * 10 + digit, sign);
    }
};
