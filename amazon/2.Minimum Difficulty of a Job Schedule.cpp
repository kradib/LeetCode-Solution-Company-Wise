//1335. Minimum Difficulty of a Job Schedule
//https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:
    
    int myrecur(vector<int> &jd, int index, int n, vector<vector<int>> &dp){
        
        if(n==1){
            return *max_element(jd.begin()+index, jd.end());
        }
        if(dp[index][n]!=-1)
            return dp[index][n];
        
        int last=jd.size()-n+1;
        int cur_max=jd[index];
        int effort= jd[index]+myrecur(jd,index+1,n-1,dp);
        for(int i=index+1;i<last;i++){
            cur_max=max(cur_max,jd[i]);
            effort=min(cur_max+myrecur(jd,i+1,n-1,dp), effort);
        }
        dp[index][n]=effort;
        
        return effort;
        
    }
    
    
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d)
            return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        
        return myrecur(jd,0,d, dp);
    }
};