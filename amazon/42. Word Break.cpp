//139. Word Break
//https://leetcode.com/problems/word-break/
class Solution {
public:
    
    bool myrecur(int index1,string s, vector<string>& wordDict){
        if(index1==s.length())
            return true;
        
        
        for(int i=0;i<wordDict.size();i++){
            if(s.length()-index1>=wordDict[i].length()){
                if(s.substr(index1,wordDict[i].length())==wordDict[i])
                    if(myrecur(index1+wordDict[i].length(),s,wordDict))
                        return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //return myrecur(0,s,wordDict);
        int n=s.length();
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<wordDict.size();j++){
                if(wordDict[j].length()<=i && wordDict[j]==s.substr(i-wordDict[j].length(),wordDict[j].length()) && dp[i-wordDict[j].length()]){
                    dp[i]=1;
                }
                if(dp[i])
                    break;
            }
        }
        
        return dp[n]==1;
        
        
        
    }
};