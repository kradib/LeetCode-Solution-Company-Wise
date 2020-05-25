

//problem link: https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    
    
    int myrecur(int x, int y,vector<vector<int>>& grid, int n, int m,vector<vector<int>> &dp){
        
        if(x==n-1 && y==m-1)
            return 1;
        if(x==n)
            return 0;
        if(y==m)
            return 0;
        
        if(grid[x][y]==1){
            dp[x][y]=0;
            return 0;
        }
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        
        
        
        dp[x][y]= myrecur(x+1,y,grid,n,m,dp) + myrecur(x,y+1,grid,n,m,dp);
        
        return dp[x][y];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        if(obstacleGrid[0][0]||obstacleGrid[n-1][m-1])
            return 0;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        
        return myrecur(0,0,obstacleGrid,n,m,dp);
        
    }
};