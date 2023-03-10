class Solution {
    bool good(int i, int j, vector<vector<int>> &g, vector<vector<int>> &vis) {
        int n = g.size(), m = g[0].size();
        if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]) return true;
        return false;
    }
    bool dfs(int i, int j, int n, int m, vector<vector<int>> &g, vector<vector<int>> &vis) {
        if(i == n - 1 && j == m - 1) return true;
        vis[i][j] = 1;
        
        if(g[i][j] == 1) {
            if(good(i, j - 1, g, vis) && (g[i][j - 1] == 4 || g[i][j - 1] == 6 || g[i][j - 1] == 1) 
            && dfs(i, j - 1, n, m, g, vis)) return true;
            if(good(i, j + 1, g, vis) && (g[i][j + 1] == 3 || g[i][j + 1] == 5 || g[i][j + 1] == 1) 
            && dfs(i, j + 1, n, m, g, vis)) return true;
        }
        else if(g[i][j] == 2) {
            if(good(i + 1, j, g, vis) && (g[i + 1][j] == 5 || g[i + 1][j] == 6 || g[i + 1][j] == 2) 
            && dfs(i + 1, j, n, m, g, vis)) return true;
            if(good(i - 1, j, g, vis) && (g[i - 1][j] == 3 || g[i - 1][j] == 4 || g[i - 1][j] == 2) 
            && dfs(i - 1, j, n, m, g, vis)) return true;
        }
        else if(g[i][j] == 3) {
            if(good(i, j - 1, g, vis) && (g[i][j - 1] == 1 || g[i][j - 1] == 4 || g[i][j - 1] == 6) 
            && dfs(i, j - 1, n, m, g, vis)) return true;
            if(good(i + 1, j, g, vis) && (g[i + 1][j] == 2 || g[i + 1][j] == 5 || g[i + 1][j] == 6)
            && dfs(i + 1, j, n, m, g, vis)) return true;
        }
        else if(g[i][j] == 4) {
            if(good(i, j + 1, g, vis) && (g[i][j + 1] == 1 || g[i][j + 1] == 3 || g[i][j + 1] == 5) 
            && dfs(i, j + 1, n, m, g, vis)) return true;
            if(good(i + 1, j, g, vis) && (g[i + 1][j] == 2 || g[i + 1][j] == 5 || g[i + 1][j] == 6)
            && dfs(i + 1, j, n, m, g, vis)) return true;
        }
        else if(g[i][j] == 5) {
            if(good(i - 1, j, g, vis) && (g[i - 1][j] == 3 || g[i - 1][j] == 4 || g[i - 1][j] == 2) 
            && dfs(i - 1, j, n, m, g, vis)) return true;
            if(good(i, j - 1, g, vis) && (g[i][j - 1] == 1 || g[i][j - 1] == 4 || g[i][j - 1] == 6) 
            && dfs(i, j - 1, n, m, g, vis)) return true;
        }
        else {
            if(good(i - 1, j, g, vis) && (g[i - 1][j] == 3 || g[i - 1][j] == 4 || g[i - 1][j] == 2) 
            && dfs(i - 1, j, n, m, g, vis)) return true;
            if(good(i, j + 1, g, vis) && (g[i][j + 1] == 3 || g[i][j + 1] == 5 || g[i][j + 1] == 1) 
            && dfs(i, j + 1, n, m, g, vis)) return true;
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));

        return dfs(0, 0, n, m, grid, vis);
    }
};