
//problem link: https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    
    
    void myrecur(int index, vector<int> &vis, int N,int &count){
        
        if(index==N+1)
            count++;
        
        
        for(int i=1;i<=N;i++){
            if(vis[i-1]==0 && (i%index==0 || index%i==0)){
                vis[i-1]=1;
                myrecur(index+1,vis,N,count);
                vis[i-1]=0;
            }
        }
        
    }
    
    
    int countArrangement(int N) {
        
        vector<int> vis(N);
        
        int count=0;
        for(int i=1;i<=N;i++){
            vis[i-1]=1;
            myrecur(2,vis,N,count);
            vis[i-1]=0;
        }
        
        return count;
        
    }
};