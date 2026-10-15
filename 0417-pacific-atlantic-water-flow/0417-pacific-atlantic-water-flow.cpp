class Solution {
public:
int m, n;
 vector<vector<int>> pacific, atlantic;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
           m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<int>(n, 0));
        atlantic.assign(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
            dfs(m - 1, j, heights, atlantic);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
     void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {
        if (vis[r][c]) return;

        vis[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }
};