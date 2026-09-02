class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> st;
        int ans = 0;

        for(int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : h[i]);

            while(!st.empty() && h[st.back()] > curr) {
                int height = h[st.back()];
                st.pop_back();

                int left = st.empty() ? -1 : st.back();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push_back(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> h(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    h[j]++;
                else
                    h[j] = 0;
            }

            ans = max(ans, largestRectangleArea(h));
        }

        return ans;
    }
};