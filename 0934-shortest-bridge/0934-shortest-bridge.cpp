class Solution {
public:
    int m, n;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void markIsland(vector<vector<int>>& grid,
                    queue<pair<int, int>>& bfsQ,
                    int r, int c) {

        queue<pair<int, int>> q;

        grid[r][c] = 2;
        q.push({r, c});
        bfsQ.push({r, c});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    grid[nx][ny] == 1) {

                    grid[nx][ny] = 2;

                    q.push({nx, ny});
                    bfsQ.push({nx, ny});
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // This queue will be used for the SECOND BFS
        queue<pair<int, int>> q;

        // Find and mark first island
        bool found = false;

        for (int i = 0; i < m && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    markIsland(grid, q, i, j);
                    found = true;
                    break;
                }
            }
        }

        // Multi-source BFS from first island
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Reached second island
                    if (grid[nr][nc] == 1) {
                        return moves;
                    }

                    // Expand through water
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};