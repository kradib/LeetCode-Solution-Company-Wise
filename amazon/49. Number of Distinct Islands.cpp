//694. Number of Distinct Islands
//https://leetcode.com/problems/number-of-distinct-islands/
class Solution {
public:
    int R,C;

    string dfs(vector<vector<int>>& grid, int r, int c, char dir) {
        if(r >= R || r < 0 || c >= C || c < 0) 
            return "";
        if(grid[r][c] == 0) 
            return "";
        string id;
        grid[r][c] = 0;
        id.push_back(dir);
        id += dfs(grid, r+1, c  , 'u');
        id += dfs(grid, r-1, c  , 'd');
        id += dfs(grid, r  , c+1, 'r');
        id += dfs(grid, r  , c-1, 'l');
        id.push_back('b');
        return id;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()) 
            return 0;
        R = grid.size();
        C = grid[0].size();

        unordered_set<string> shapes;
        for(int r=0; r < R; ++r)
            for(int c=0; c < C; ++c)
                if(grid[r][c] == 1)
                    shapes.insert(dfs(grid, r, c, 's'));

        return shapes.size();
    }
};