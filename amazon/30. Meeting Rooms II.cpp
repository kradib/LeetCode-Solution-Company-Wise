//253. Meeting Rooms II
//https://leetcode.com/problems/meeting-rooms-ii/
class Solution {
public:
    
    static bool mycomp(vector<int> a,vector<int> b ){
        
        if(a[0]<b[0])
            return true;
        else if(a[0]>b[0])
            return false;
        else {
            if(a[1]<b[1])
                return true;
            else return false;
        }
        
        
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        if(n==0)
            return 0;
        
        sort(intervals.begin(),intervals.end(),mycomp);
        
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(auto it: intervals){
            if(pq.empty()){
                pq.push(it[1]);
            }
            else{
                int current_top=pq.top();
                if(current_top<=it[0]){
                    pq.pop();
                    pq.push(it[1]);
                }
                else{
                    pq.push(it[1]);
                }
            }
        }
        
        
        return pq.size();
        
    }
};