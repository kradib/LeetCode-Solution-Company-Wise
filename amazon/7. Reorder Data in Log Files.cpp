//937. Reorder Data in Log Files
//https://leetcode.com/problems/reorder-data-in-log-files/
class Solution {
public:
    
    
    static bool mycomp(string s1,string s2){
        
        string firstword1="";
        string firstword2="";
        int start1=0,start2=0;
        for(int i=0;s1[i]!=' ';i++,start1++){
            firstword1+=string(1,s1[i]);
            
        }
        string newstr1=s1.substr(start1,s1.length()-start1);
        for(int i=0;s2[i]!=' ';i++,start2++){
            firstword2+=string(1,s2[i]);
        }
        string newstr2=s2.substr(start2,s2.length()-start2);
        
        if(newstr1<newstr2)
            return true;
        else if(newstr1>newstr2)
            return false;
        else{
            return (firstword1<firstword2);
        }
        
        
        
    }
    
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digLogs;
        vector<string> letLogs;
        int n=logs.size();
        if(n==0)
            return letLogs;
        
        for(int i=0;i<n;i++){
            string p=logs[i];
            int w=0;
            while(p[w]!=' ')
                w++;
            if(logs[i][w+1]>='0' &&logs[i][w+1]<='9'){
                digLogs.push_back(logs[i]);
            }
            else{
                letLogs.push_back(logs[i]);
            }
        }
        
        sort(letLogs.begin(),letLogs.end(),mycomp);
        
        for(int i=0;i<digLogs.size();i++)
            letLogs.push_back(digLogs[i]);
        
        
        return letLogs;
        
    }
};