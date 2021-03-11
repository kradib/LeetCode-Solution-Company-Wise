//1167. Minimum Cost to Connect Sticks
//https://leetcode.com/problems/minimum-cost-to-connect-sticks/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>>  pq;
        for(int i=0;i<sticks.size();i++)
            pq.push(sticks[i]);
        int sum=0;
        while(pq.size()>=2){
            int temp1=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.pop();
            sum+=temp1+temp2;
            pq.push(temp1+temp2);
            
        }
        
        return sum;
        
    }
};