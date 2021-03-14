//17. Letter Combinations of a Phone Number
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    
    void myrecur(string digits,int index,string cur, map<char,vector<char>> mymap,vector<string>& mylist){
        
        if(digits.length()==index){
            mylist.push_back(cur);
            return;
        }
        vector<char> p=mymap[digits[index]];
        for(int i=0;i<p.size();i++){
            myrecur(digits,index+1,cur+string(1,p[i]),mymap,mylist);
        }
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> mylist;
        if(digits.length()==0)
            return mylist;
        map<char, vector<char>> mymap;
        vector<char> v1{'a','b','c'};
        vector<char> v2{'d','e','f'};
        vector<char> v3{'g','h','i'};
        vector<char> v4{'j','k','l'};
        vector<char> v5{'m','n','o'};
        vector<char> v6{'p','q','r','s'};
        vector<char> v7{'t','u','v'};
        vector<char> v8{'w','x','y','z'};
        mymap['2']=v1;
        mymap['3']=v2;
        mymap['4']=v3;
        mymap['5']=v4;
        mymap['6']=v5;
        mymap['7']=v6;
        mymap['8']=v7;
        mymap['9']=v8;
        
        
        
        
        myrecur(digits,0,"",mymap,mylist);
        
        return mylist;
        
        
    }
};