//127. Word Ladder
//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    map<string,vector<int>> mymap;
    set<int> *graph;
    void preprocess(vector<string>& wordList){
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].length();j++){
                string temp=wordList[i];
                temp[j]='*';
                mymap[temp].push_back(i);
            }            
        }
    }
    void createGraph(vector<string>& wordList ){
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].length();j++){
                string temp=wordList[i];
                temp[j]='*';
                for(auto it: mymap[temp]){
                    if(it!=i && graph[i].find(it)==graph[i].end()){
                        graph[i].insert(it);
                    }
                }
            }
        }
    }
    
    void print(set<int> &st){
        
        for(auto it= st.begin();it!=st.end();it++)
            cout<<*it<<" ";
        cout<<endl;
        
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;
        int source=0;
        vector<string>::iterator ik=find(wordList.begin(),wordList.end(),beginWord);
        if(ik==wordList.end())
            wordList.insert(wordList.begin(),beginWord);
        else
            source = ik-wordList.begin();
            
        
        int n = wordList.size();
        preprocess(wordList);
        graph = new set<int>[n];
        createGraph(wordList);
        
        // for(int i=0;i<n;i++){
        //     print(graph[i]);
        // }
        
        
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(source);
        q.push(-1);
        int level=0;
        while(!q.empty()){
            int index=q.front();
            q.pop();
            if(index==-1){
                if(!q.empty()){
                    q.push(-1);
                    level++;
                }
            }
            else{
                vis[index]=1;
                if(wordList[index]==endWord)
                    return level+1;
                
                for(auto it=graph[index].begin();it!=graph[index].end();it++){
                    if(vis[*it]==0){
                        q.push(*it);
                    }
                }
                
            }
        }
        
        return 0;
        
        
        
        
        
        
        
        
    }
};