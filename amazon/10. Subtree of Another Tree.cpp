//572. Subtree of Another Tree
//https://leetcode.com/problems/subtree-of-another-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool isSubtreerecur(TreeNode* s,TreeNode* t){
        
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        
        if(s->val==t->val)
            return isSubtreerecur(s->left,t->left) && isSubtreerecur(s->right,t->right);
        else
            return false;
        
    }
    
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        queue<TreeNode*> q;
        q.push(s);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==t->val && isSubtreerecur(temp->left,t->left) && isSubtreerecur(temp->right,t->right))
            return true;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return false;    
    }
    
    
};