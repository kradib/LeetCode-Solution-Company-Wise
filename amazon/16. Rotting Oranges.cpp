994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        //vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        int blank=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
                else if(grid[i][j]==0)
                    blank++;
            }
        }
        if(q.size()+blank==n*m)
            return 0;
        
        if(q.empty())
            return -1;
        
        q.push(make_pair(-1,-1));
        
        
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            int r=temp.first;
            int c=temp.second;
            
            if(r==-1 && c==-1){
                if(!q.empty()){
                    q.push(make_pair(-1,-1));
                    count++;
                }
                
            }
            else{
                if(r-1>=0 && grid[r-1][c]==1){
                    q.push(make_pair(r-1,c));
                    grid[r-1][c]=2;    
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    q.push(make_pair(r,c-1));
                    grid[r][c-1]=2;    
                }
                if(r+1<n && grid[r+1][c]==1){
                    q.push(make_pair(r+1,c));
                    grid[r+1][c]=2;    
                }
                if(c+1<m && grid[r][c+1]==1){
                    q.push(make_pair(r,c+1));
                    grid[r][c+1]=2;    
                }
                
            }   
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;
        }
        return count;
        
        
    }
};