//212. Word Search II
//https://leetcode.com/problems/word-search-ii/
class Treenode{
    public:
    char l;
    map<char,Treenode*> mymap;
    string s;
    Treenode(){
        l='.';
        s="";
    }
};

class Solution {
public:
    
    void dfs(int i ,int j,vector<vector<char>>& board, Treenode *root, vector<string> &result,int n,int m ){
        char letter=board[i][j];
        Treenode* cur=root->mymap[letter];
        if(cur->s!=""){
            result.push_back(cur->s);
            cur->s="";
        }
        board[i][j]='#';
        int x[4]={0,-1,0,1};
        int y[4]={1,0,-1,0};
        
        for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m)
                continue;
            if(cur->mymap.find(board[ni][nj])!=cur->mymap.end()){
                dfs(ni,nj,board,cur,result,n,m);
            }
        }
        board[i][j]=letter;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        int n=board.size();
        if(n==0)
            return result;
        int m=board[0].size();
        Treenode *root=new Treenode();
        
        for(string str:words){
            Treenode *node=root;
            for(char c:str){
                if(node->mymap.find(c)==node->mymap.end()){
                    Treenode *newnode=new Treenode();
                    newnode->l=c;
                    node->mymap[c]=newnode;
                    node=newnode;
                }
                else{
                    Treenode* newnode=node->mymap[c];
                    node=newnode;
                }
                
            }
            node->s=str;
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->mymap.find(board[i][j])!=root->mymap.end()){
                    dfs(i,j,board,root,result,n,m);
                }
            }
        }
        
        return result;
    }
};