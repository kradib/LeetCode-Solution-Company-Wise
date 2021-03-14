//682. Baseball Game
//https://leetcode.com/problems/baseball-game/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                if(!st.empty()){
                    int a=st.top();
                    st.pop();
                    if(!st.empty()){
                        int b=st.top();
                        int c=a+b;
                        st.push(a);
                        st.push(c);
                    }
                    else{
                        st.push(a);
                    }
                }
            }
            else if(ops[i]=="D"){
                if(!st.empty()){
                    int a=st.top();
                    st.push(a*2);
                }
            }
            else if(ops[i]=="C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
        
        
    }
};