//547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    
    int* vis;
    int* parent;
    int* rank;
    
    
    
    int find(int* parent, int i){
        
        if(parent[i]==-1)
            return i;
        return find(parent,parent[i]);
    }
    
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        vis=new int[n];
        parent=new int[n];
        rank=new int[n];
        
        for(int i=0;i<n;i++){
            vis[i]=0;
            parent[i]=-1;
            rank[i]=0;
        }
        
        for(int i=0;i<M.size();i++){
            for(int j=i+1;j<M.size();j++){
                if(M[i][j]){
                    int x=find(parent,i);
                    int y=find(parent,j);
                    if(x==y)
                        continue;
                    if(rank[x]<rank[y]){
                        parent[x]=y;
                        
                    }
                    else if(rank[x]>rank[y]){
                        parent[y]=x;
                        
                    }
                    else{
                        parent[y]=x;
                        rank[x]++;
                    }
                }
                
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
           
            if(parent[i]==-1)
                count++;
        }
            
        
        return count;
    }
};