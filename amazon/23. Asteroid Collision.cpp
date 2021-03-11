//735. Asteroid Collision
//https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        
        for(int i=0;i<a.size();i++){

            if(st.empty() || a[i]>0)
                st.push(a[i]);
            else{
                int val=abs(a[i]);
                while(true){
                    if(st.top()<0){
                        st.push(a[i]);
                        break;
                    }
                    else if(st.top()>val)
                        break;
                    else if(st.top()==val){
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        if(st.empty()){
                            st.push(a[i]);
                            break;
                        }

                    }

                }
        
            }
        }
        
        vector<int> myvec(st.size());
        int index=st.size()-1;
        while(!st.empty()){
            myvec[index]=st.top();
            index--;
            st.pop();
        }
        
        return myvec;
    }
};