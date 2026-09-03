class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Positive overflow check (INT_MAX = 2147483647)
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            // Negative overflow check (INT_MIN = -2147483648)
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            ans = ans * 10 + pop;
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna