class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis = grid;
        //making queue in which we will fill rotten oranges
        queue<pair<int, int>> q;
        int count_1 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 2) {
                    q.push({i, j});
                }
                if (vis[i][j] == 1) {
                    count_1++;
                }
            }
        }
        
        if (count_1 == 0)
            return 0;
        if (q.empty())
            return -1;
        
        int ans = -1;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 and i < m and j >= 0 and j < n and vis[i][j] == 1) {
                        vis[i][j] = 2;
                        count_1--;
                        q.push({i, j});
                    }
                }
            }
            ans++;
        }
        
        if (count_1 == 0)
            return ans;
        return -1;
    }
};