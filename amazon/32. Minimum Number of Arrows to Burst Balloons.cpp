//452. Minimum Number of Arrows to Burst Balloons
//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    
    static bool mycomp(vector<int> &a, vector<int> &b){
        
        if(a[1]<b[1])
            return true;
        else if(a[1]>b[1])
            return false;
        else
            return a[0]<b[0];
        
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),mycomp);
        
        stack<int> st;
        
        for(auto &it: points){
            if(st.empty()){
                st.push(it[1]);
            }
            else{
                if(it[0]>st.top()){
                    st.push(it[1]);
                }
                
            }
        }
        return st.size();
        
    }
};