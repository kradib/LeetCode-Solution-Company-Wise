//55. Jump Game
//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(last<=i+nums[i])
                last=i;
        }
        
        return (last==0);
        
    }
};