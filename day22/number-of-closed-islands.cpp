class Solution {
public:
    int ans = 0, count = 0;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (isValidDimentions(i, j, grid) && grid[i][j] == 0) {
                grid[i][j] = -1;

                dfs(i + 1, j, grid);
                dfs(i - 1, j, grid);
                dfs(i, j - 1, grid);
                dfs(i, j + 1, grid);
            } else if (isValidDimentions(i, j, grid) 
                        && (grid[i][j] == -1 || grid[i][j] == 1))
                            return;
            else count += 1;
    }

    bool isValidDimentions(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 &&  j < grid[0].size();
    }

    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    count = 0;
                    dfs(i, j, grid);
                    if (count == 0) ans += 1;
                }
            }
        }

        return ans;
    }
};
