//973. K Closest Points to Origin
//https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    
    static bool myfunc(vector<int> a, vector<int> b){
        
        if(a[0]*a[0]+a[1]*a[1]<=b[0]*b[0]+b[1]*b[1])
            return true;
        return false;
        
        
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // sort(points.begin(),points.end(),myfunc);
        vector<vector<int>> result;
        
        auto comp=[](pair<int,int> a, pair<int,int> b){
            return pow(a.first,2)+pow(a.second,2)>=pow(b.first,2)+pow(b.second,2);
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        
        for(auto it:points){
            pq.push(make_pair(it[0],it[1]));
        }
        while(K--){
            result.push_back(vector<int>{pq.top().first,pq.top().second});
            pq.pop();
        }    
        return result;
    }
};