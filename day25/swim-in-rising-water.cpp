class Solution {
public:
    #define arr pair<int, int>
    int vis[50][50];

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        vis[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0});

        while (!pq.empty()) {
            auto [val, ind] = pq.top();
            pq.pop();
            ans = max(ans, val);

            for (int i = 0; i < 4; ++i) {
                int r = ind/n + dir[i], c = ind%n + dir[i+1];
                if (min(r, c) >= 0 && max(r, c) < n && vis[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r*n + c});
                    vis[r][c] = 1;
                }
            }
        }
        return ans;
    }
};
