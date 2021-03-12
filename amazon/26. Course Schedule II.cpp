//210. Course Schedule II
//https://leetcode.com/problems/course-schedule-ii/submissions/
class Solution {
public:
    vector<int> *graph;
    stack<int> st;
    
    bool topoSort(int i, vector<int> &vis){
        
        
        vis[i]=2;
        
        for(auto &it: graph[i]){
            if(vis[it]==0 && topoSort(it,vis))
                return true;
            else
                if(vis[it]==2)
                    return true;
        }
        
        st.push(i);
        vis[i]=1;
        return false;
        
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        graph= new vector<int>[n]; 
        
        for(auto it: pre){
            graph[it[1]].push_back(it[0]);
        }
        
        
        
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && topoSort(i,vis)){
                return ans;
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};