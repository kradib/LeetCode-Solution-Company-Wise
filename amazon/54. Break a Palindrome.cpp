//1328. Break a Palindrome
//https://leetcode.com/problems/break-a-palindrome/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)
            return "";
        for(int i=0;i<palindrome.length()/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        // if all are a's or all are a's except palindrome[mid]
        //e.g: "aaaa", "aba"
        //then change the last character to "b"
        palindrome[palindrome.length()-1]='b';
        return palindrome;
            
        
    }
};