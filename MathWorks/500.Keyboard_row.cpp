
//problem link: https://leetcode.com/problems/keyboard-row/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1{'Q','W','E','R','T','Y','U','I','O','P'};
        set<char> s2{'A','S','D','F','G','H','J','K','L'};
        set<char> s3{'Z','X','C','V','B','N','M'};
        
        vector<string> result;
        
        for(string s: words){
            int found=0;
            if(s1.find(toupper(s[0]))!=s1.end())
                found=1;
            if(s2.find(toupper(s[0]))!=s2.end())
                found=2;
            if(s3.find(toupper(s[0]))!=s3.end())
                found=3;
            bool flag=true;
            for(int i=1;i<s.length();i++){
                if(found==1){
                    if(s1.find(toupper(s[i]))==s1.end()){
                        flag=false;
                        break;
                    }
                }
                if(found==2){
                    if(s2.find(toupper(s[i]))==s2.end()){
                        flag=false;
                        break;
                    }
                }
                if(found==3){
                    if(s3.find(toupper(s[i]))==s3.end()){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
                result.push_back(s);
            
        }
        
        
                     
        return result;
                     
        
            
            
    }
};