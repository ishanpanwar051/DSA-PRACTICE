class Solution {
public:

    long long power(long long x, long long y) {
        long long MOD = 1e9 + 7;
        long long ans = 1;

        while (y > 0) {
            if (y & 1)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {

        long long MOD = 1e9 + 7;
        long long ans = 0;

        for (long long num : nums) {

            int width = num % 10;
            long long d = num / 10;

            int digits = to_string(d).length();

            long long divisor = 1;

            for (int i = 0; i < digits - width; i++) {
                divisor *= 10;
            }

            long long x = d / divisor;
            long long y = d % divisor;

            ans = (ans + power(x, y)) % MOD;
        }

        return ans;
    }
};