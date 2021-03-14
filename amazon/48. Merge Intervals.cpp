//56. Merge Intervals
//https://leetcode.com/problems/merge-intervals/

class Solution {
    
    
public:
    static bool myfunc(vector<int> c, vector<int> d){
        if(c[0]<d[0]){
            return true;
        }
        else if(c[0]>d[0]){
            return false;
        }
        else{
            return (c[1]<d[1]);
            
        }
        
        
    }
     
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if(a.size()==0)
            return a;
        sort(a.begin(),a.end(),myfunc);
        int n=a.size();
        stack<vector<int>> st;
        st.push(a[0]);
        // cout<<"pushed\n";
        for(int i=1;i<n;i++){
            if(st.top()[1]<a[i][0]){
                st.push(a[i]);
            }
            else if(st.top()[1]<a[i][1]){
                vector<int> b(2);
                b[0]=st.top()[0];
                b[1]=a[i][1];
                st.pop();
                st.push(b);
            }
                
        }
        vector<vector<int>> myvec(st.size());
        int k=st.size()-1;
        for(int i=k;i>=0;i--){
            myvec[i]=st.top();
            st.pop();
        }
        
        return myvec;
    }
    
};