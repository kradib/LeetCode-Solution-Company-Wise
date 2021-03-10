//1041. Robot Bounded In Circle
//https://leetcode.com/problems/robot-bounded-in-circle/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        string mystr=instructions+ instructions+ instructions+ instructions;
        //N W S R
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        
        int face=0;
        int r=0,c=0;
        for(int i=0;i<mystr.length();i++){
            if(mystr[i]=='L'){
                face=(face+3)%4;
            }
            else if(mystr[i]=='R'){
                face=(face+1)%4;
            }
            else{
                r+=dir[face][0];
                c+=dir[face][1];
            }
        }
        
        return (r==0 && c==0);
        
        
        
    }
};