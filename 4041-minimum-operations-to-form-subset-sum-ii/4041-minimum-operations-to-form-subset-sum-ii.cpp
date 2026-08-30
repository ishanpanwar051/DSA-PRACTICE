class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        // dp[s] = minimum operations to achieve subset sum s
        vector<int> dp(sum + 1, INF);
        dp[0] = 0; // 0 sum requires 0 operations

        for (int x : nums) {
            // Step 1: Find all reachable values v <= sum and their minimum cost from x
            unordered_map<int, int> min_cost;
            int k = 0;
            int curr = x;
            
            while (curr > 0) {
                int m = 0;
                long long val = curr;
                while (val <= sum) {
                    if (!min_cost.count(val) || k + m < min_cost[val]) {
                        min_cost[val] = k + m;
                    }
                    val *= 2;
                    m++;
                }
                curr /= 2;
                k++;
            }

            // Step 2: Group 0/1 Knapsack transition
            vector<int> next_dp = dp; // Option 0: Don't pick this element
            
            for (auto& [v, c] : min_cost) {
                for (int s = v; s <= sum; ++s) {
                    if (dp[s - v] != INF) {
                        next_dp[s] = min(next_dp[s], dp[s - v] + c);
                    }
                }
            }
            dp = move(next_dp);
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};