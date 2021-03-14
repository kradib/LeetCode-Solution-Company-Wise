//1120. Maximum Average Subtree
//https://leetcode.com/problems/maximum-average-subtree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    double avg;
    
public:
    
    pair<double,double> buildMyTree(TreeNode* root){
        if(!root){
            return make_pair(0.0,0.0);
        }
        if(!root->left && !root->right){
            if(root->val>avg)
                avg=(double)root->val;
            return make_pair((double)root->val,1.0);
        }
            
        
        //MyTree* cur= new MyTree(root,root->val,1);
        pair<double,double> l = buildMyTree(root->left);
        pair<double,double> r = buildMyTree(root->right);
        
        double cur_sum=root->val+l.first+r.first;
        double cur_count=1+l.second+r.second;
        
        if(cur_sum/cur_count>avg)
            avg=cur_sum/cur_count;
        
        return make_pair(cur_sum,cur_count);
         
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        avg=0.0;
        
        buildMyTree(root);
        return avg;
        
    }
};