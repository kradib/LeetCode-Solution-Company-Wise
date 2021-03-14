//103. Binary Tree Zigzag Level Order Traversal
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(!root)
            return arr;
        
        vector<int> cur;
        int flag=1;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                if(flag){
                    flag=1-flag;
                    arr.push_back(cur);
                    cur.clear();
                    if(!q.empty())
                        q.push(NULL);
                }
                else{
                    flag=1-flag;
                    reverse(cur.begin(),cur.end());
                    arr.push_back(cur);
                    cur.clear();
                    if(!q.empty())
                        q.push(NULL);
                }
            }
            else{
                cur.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return arr;
        
    }
};