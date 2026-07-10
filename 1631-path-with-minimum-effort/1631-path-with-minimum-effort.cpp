class Solution {
public:
    bool possible(vector<vector<int>>& heights, int effort) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Destination reached
            if (r == m - 1 && c == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    int diff = abs(heights[r][c] - heights[nr][nc]);

                    if (diff <= effort) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int left = 0;
        int right = 1000000;
        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (possible(heights, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};