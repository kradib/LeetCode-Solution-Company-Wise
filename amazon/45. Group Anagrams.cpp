//49. Group Anagrams
//https://leetcode.com/problems/group-anagrams/
class Solution {
public:
        
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> myvector;
        
        
        map<string,vector<string>> mymap;
        
        for(int i=0;i<strs.size();i++){
            string p=strs[i];
            sort(p.begin(),p.end());
            mymap[p].push_back(strs[i]);
        }
        for(auto it=mymap.begin();it!=mymap.end();it++){
            myvector.push_back(it->second);
        }
        return myvector;
        
    }
};