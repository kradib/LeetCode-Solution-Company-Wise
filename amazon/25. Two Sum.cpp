//1. Two Sum
//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mymap;
        vector<int> p(2);
        for(int i=0;i<n;i++){
            if(mymap.find(target-nums[i])!=mymap.end()){
                p[0]=mymap[target-nums[i]];
                p[1]=i;
                return p;
            }
            else
                mymap[nums[i]]=i;
        }
        
        
        return p;
    }
};