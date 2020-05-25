//problem link: https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
    int bulbSwitch(int n) {
        
//O(n*sqrt(n))  gives TLE      
        
        
//         if(n==0 || n==1)
//             return n;
        
//         vector<int> dp(n,1);
//         for(int i=2;i<=n;i++){
//             for(int j=i;j<=n;j+=i)
//                 dp[j-1]=1-dp[j-1];
//         }
//         int p=0;
//         for(int i=0;i<n;i++)
//             if(dp[i])
//                 p++;
        
//         return p;
        //find perfect squares within thr range [1,n]
        return (int)(sqrt(n));
        
    }
};