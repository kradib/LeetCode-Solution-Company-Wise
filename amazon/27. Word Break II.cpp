//140. Word Break II
//https://leetcode.com/problems/word-break-ii/submissions/

class Solution {
public:
    set<string> dict;
    map<string,vector<vector<string>>> hash;
    vector<vector<string>> myrecur(string s){
        vector<vector<string>> sen;
        if(s==""){
            vector<string> emp;
            sen.push_back(emp);
            return sen;
        }
        
        if(hash.find(s)==hash.end()){
            hash[s]=sen;
        }
        else{
            return hash[s];
        }
        
        for(int i=1;i<=s.length();i++){
            string substring = s.substr(0,i);
            if(dict.find(substring)!=dict.end()){
                string rem=s.substr(i,s.length()-i);
                vector<vector<string>> fromrem=myrecur(rem);
                for(auto it:fromrem){
                    it.insert(it.begin(),substring);
                    hash[s].push_back(it);
                }
            }
        }
        
        return hash[s];
        
        
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto ip: wordDict)
            dict.insert(ip);
        vector<vector<string>> sen=myrecur(s);
        vector<string> ans;
        for(auto &it:sen){
            string add="";
            for(auto &ij:it)
                add+=ij+" ";
            add.pop_back();
            ans.push_back(add);
        }
        return ans;
    }
};