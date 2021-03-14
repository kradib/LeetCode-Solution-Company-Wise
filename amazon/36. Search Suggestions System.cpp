//1268. Search Suggestions System
//https://leetcode.com/problems/search-suggestions-system/
class Trie{
    public:
    char c;
    map<char, Trie*> child;
    string str;
    Trie(char a){
        c=a;
        str="";
    }
}; 




class Solution {
    
    //Trie* root;
    
public:
    
    void addStringinTrie(string &s, Trie* root){
        Trie* node=root;
        for(int i=0;i<s.length();i++){
            if(node->child.find(s[i])==node->child.end()){
                node->child[s[i]] = new Trie(s[i]);
            }
            node=node->child[s[i]];
        }
        node->str=s;
    }
    
    void createTrie(vector<string>& products, Trie* root){
        for(auto &it: products){
            addStringinTrie(it, root);
        }
    }
    
    
    void dfs(Trie* node, vector<string> &ans, int &level){
        if(level>=3)
            return;
        if(!node)
            return;
        if(node->str!=""){
            level++;
            ans.push_back(node->str);
        }
            
        
        for(auto [k,v]:node->child){
            
            dfs(v,ans,level);
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *root=new Trie('.');
        createTrie(products,root);
        
        vector<vector<string>> ans;
        
        for(int i=0;i<searchWord.length();i++){
            if(root->child.find(searchWord[i])==root->child.end()){
                vector<string> temp;
                for(int j=i;j<searchWord.length();j++){
                    ans.push_back(temp);
                }
                break;
            }
            else{
                root=root->child[searchWord[i]];
                vector<string> temp;
                int level=0;
                dfs(root,temp,level);
                ans.push_back(temp);    
            }
            
        }
        return ans;
        
        
    }
};