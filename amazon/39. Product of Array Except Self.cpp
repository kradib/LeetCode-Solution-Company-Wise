//238. Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
            return {};
        vector<int> result(n);
        
        result[0]=1;
        int l=nums[0];
        for(int i=1;i<n;i++){
            result[i]=l*result[i-1];
            l=nums[i];
        }
        
        int r=nums[n-1];
        for(int i=n-2;i>=0;i--){
            result[i]*=r;
            r*=nums[i];
        }
        
        return result;
        
        
    }
};