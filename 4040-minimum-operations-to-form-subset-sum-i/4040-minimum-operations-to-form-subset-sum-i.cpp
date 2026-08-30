class Solution {
public:

    int minOperations(vector<int>& nums, int sum) {

        const int INF = 1e9;

        // dp[s] = minimum operations needed
        // to make sum s
        vector<int> dp(sum + 1, INF);

        dp[0] = 0;

        for (int x : nums) {

            // value -> minimum operations
            vector<pair<int, int>> options;

            // Original value
            if (x <= sum) {
                options.push_back({x, 0});
            }

            // Division:
            // x -> x/2 -> x/4 -> ...
            int value = x;
            int cost = 0;

            while (value > 0) {

                if (value <= sum) {
                    options.push_back({value, cost});
                }

                value /= 2;
                cost++;
            }

            // Multiplication:
            // x -> 2x -> 4x -> ...
            value = x;
            cost = 0;

            while (value <= sum / 2) {

                value *= 2;
                cost++;

                options.push_back({value, cost});
            }

            // This element can be used only ONCE
            // so traverse backwards.
            for (int current = sum; current >= 0; current--) {

                if (dp[current] == INF)
                    continue;

                for (auto [value, operations] : options) {

                    if (current + value > sum)
                        continue;

                    dp[current + value] = min(
                        dp[current + value],
                        dp[current] + operations
                    );
                }
            }
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};