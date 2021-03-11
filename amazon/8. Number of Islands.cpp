//200. Number of Islands
//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void dfs(int x, int y, vector<vector<char>>& grid,vector<vector<int>>& vis){
        
        vis[x][y]=1;
        if(x-1>=0 && vis[x-1][y]==0 && grid[x-1][y]=='1'){
            dfs(x-1,y,grid,vis);
        }
        if(y-1>=0 && vis[x][y-1]==0 && grid[x][y-1]=='1'){
            dfs(x,y-1,grid,vis);
        }
        if(x+1<grid.size() && vis[x+1][y]==0 && grid[x+1][y]=='1'){
            dfs(x+1,y,grid,vis);
        }
        if(y+1<grid[0].size() && vis[x][y+1]==0 && grid[x][y+1]=='1'){
            dfs(x,y+1,grid,vis);
        }
        
        
        
        
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        
        int n=grid.size();
        if(n==0)
            return 0;
        
        int m=grid[0].size();
        
        
        vector<vector<int>> vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<int>(m);
            for(int j=0;j<m;j++)
                vis[i][j]=0;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
        
            
        
    }
};