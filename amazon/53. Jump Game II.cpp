//45. Jump Game II
//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]!=INT_MAX && j+nums[j]>=i){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        
        return dp[n-1];
    }
};

/////////////LC solution O(n) ///////////////////////

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int max_coverage=0, last_index=0;
        int jump=0;
        for(int i=0;i<nums.size();i++){
            
            max_coverage=max(max_coverage,i+nums[i]);
            
            if(last_index==i){
                last_index=max_coverage;
                jump++;
            }
            if(last_index>=nums.size()-1)
                return jump;
        }
        return jump;
    }
};