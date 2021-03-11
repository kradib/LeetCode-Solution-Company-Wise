//763. Partition Labels
//https://leetcode.com/problems/partition-labels/
class node{
    public:
    int start;
    int end;
};
class Solution {
public:
    static bool myfunc(node a, node b){
        if(a.start<b.start)
            return true;
        else
            return false;
    }
    vector<int> partitionLabels(string s) {
        map<char,vector<int>> mymap;
        for(int i=0;i<s.length();i++){
            mymap[s[i]].push_back(i);
        }
        vector<node> mylist;
        for(auto it=mymap.begin();it!=mymap.end();it++){
            node p;
            p.start=it->second[0];
            p.end=it->second[it->second.size()-1];
            mylist.push_back(p);
        }
        sort(mylist.begin(),mylist.end(),myfunc);
        
        vector<int> result;
        
        if(mylist.size()==0)
            return result;
        stack<int> st;
        st.push(mylist[0].start);
        st.push(mylist[0].end);
        for(int i=1;i<mylist.size();i++){
            if(mylist[i].start<st.top()){
                if(mylist[i].end>st.top()){
                    st.pop();
                    st.push(mylist[i].end);
                }
            }
            else{
                st.push(mylist[i].start);
                st.push(mylist[i].end);
            }
        }
        
        while(!st.empty()){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            result.insert(result.begin(),a-b+1);
        }
        
    
        return result;
        
    }
};