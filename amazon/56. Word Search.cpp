//79. Word Search
//https://leetcode.com/problems/word-search/

class Solution {
public:
    bool safe(int i,int j,int m,int n,int** vis){
        if(i>=0 && j>=0 && i<m && j<n && vis[i][j]==0)
            return true;
        return false;
    }
    bool myrecur(int i, int j, int m, int n, int index,int** vis,vector<vector<char>>& board, string word){
        if(index==word.length())
            return true;
        if(!safe(i,j,m,n,vis))
            return false;
        
       
        
        if(word[index]!=board[i][j])
            return false;
        
        vis[i][j]=1;
        if(myrecur(i+1,j,m,n,index+1,vis,board,word))
            return true;
        
        else if(myrecur(i-1,j,m,n,index+1,vis,board,word))
            return true;
        
        else if(myrecur(i,j+1,m,n,index+1,vis,board,word))
            return true;
        
        else if(myrecur(i,j-1,m,n,index+1,vis,board,word))
            return true;
        else 
            vis[i][j]=0;
        
        
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0)
            return false;
        if(board.size()==0)
            return false;
        int m=board.size();
        int n=board[0].size();
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    int** vis=(int**)(malloc(sizeof(int*)*m));
                    for(int k=0;k<m;k++){
                        vis[k]=(int*)(malloc(sizeof(int)*n));
                        for(int l=0;l<n;l++)
                            vis[k][l]=0;
                    }
                       
                    if(myrecur(i,j,m,n,0,vis,board,word))
                        return true;
                }
            }
        }
        
        return false;
        
    }
};