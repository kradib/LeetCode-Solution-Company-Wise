//323. Number of Connected Components in an Undirected Graph
//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
class Solution {
public:
    
    int find(vector<int> &parent, int i){
        
        if(parent[i]==-1)
            return i;
        
        return find(parent,parent[i]);
        
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        
        for(auto it: edges){
            
            int source=it[0];
            int dest=it[1];
            
            int x=find(parent,source);
            int y=find(parent,dest);
            
            if(x==y)
                continue;
            else{
                if(rank[x]>rank[y]){
                    parent[y]=x;
                }
                else if(rank[y]>rank[x]){
                    parent[x]=y;
                }
                else{
                    parent[y]=x;
                    rank[x]++;
                }
            }
            
        }
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1)
                count++;
        }
        return count;
        
        
        
    }
};