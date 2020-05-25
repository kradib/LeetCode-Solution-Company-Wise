
problem link: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

class Solution {
public:
    
    
    void myrecur(vector<int>& preorder, int &start, int min, int max){
        
        if(start==preorder.size())
            return;
        
        if(preorder[start]>max || preorder[start]<min)
        return;
        
        int val=preorder[start++];
        myrecur(preorder,start,min,val);
        myrecur(preorder,start,val,max);
        
        
    }
    
    bool verifyPreorder(vector<int>& preorder) {
       
        int start=0;
        int min=INT_MIN;
        int max=INT_MAX;
        
        
        myrecur(preorder,start,min,max);
        
        return start==preorder.size();
        
        
    }
};