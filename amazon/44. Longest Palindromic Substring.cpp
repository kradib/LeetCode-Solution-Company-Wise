//5. Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        
        int start=0;
        int n=s.length();
        int maxlen=1;
        for(int i=1;i<n;i++){
            
            int low=i-1;
            int high=i;
            
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxlen<high-low+1){
                    maxlen=high-low+1;
                    start=low;
                }
                low--;
                high++;
            }
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxlen<high-low+1){
                    maxlen=high-low+1;
                    start=low;
                }
                low--;
                high++;
            }
            
            
        }
        
        
        return s.substr(start,maxlen);
    }
};