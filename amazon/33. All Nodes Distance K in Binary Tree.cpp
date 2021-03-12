//863. All Nodes Distance K in Binary Tree
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solution/
////////////My Solution /////////////////////////////////////

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
    
    map<TreeNode*, vector<TreeNode*>> hashmap;
    set<TreeNode*> visited;
    int reached;
    
    void buildtable(TreeNode* root,TreeNode* parent){
        
        if(!root)
            return;
        
        if(root->left){
            hashmap[root].push_back(root->left);
            buildtable(root->left, root);
        }
        if(root->right){
            hashmap[root].push_back(root->right);
            buildtable(root->right, root);
        }
        if(parent!=NULL)
            hashmap[root].push_back(parent);
        
    }
    void dfs(TreeNode* target, int level, vector<int> &ans){
        if(!target)
            return;
        if(reached==level){
            ans.push_back(target->val);
            return;
        }
        
        visited.insert(target);
        for(auto it: hashmap[target]){
            if(visited.find(it)==visited.end())
            dfs(it,level+1,ans);
        }
            
        
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildtable(root,NULL);
        
        reached = K;
        vector<int> ans;
        
        dfs(target,0, ans);
        return ans;
    }
};


//////////////////////////// LC solution///////////////////////

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
    vector<int> ans;
    int K;
    //addnode adds node at K-dist
    void addnode(TreeNode* cur, int dist){
        if(!cur)
            return;
        if(dist==K){
            ans.push_back(cur->val);
            return;
        }
            
        addnode(cur->left,dist+1);
        addnode(cur->right,dist+1);
        
    }
    
    int dfs(TreeNode* cur, TreeNode* target){
        
        if(!cur)
            return -1;
        if(cur==target){
            addnode(cur,0);
            return 1;
        }
        else{
            int l=dfs(cur->left,target);
            int r=dfs(cur->right,target);
            
            if(l!=-1){
                if(l==K){
                    ans.push_back(cur->val);
                }
                else
                addnode(cur->right, l+1);
                return l+1;
            }
            else if(r!=-1){
                if(r==K){
                    ans.push_back(cur->val);
                }
                else
                addnode(cur->left, r+1);
                return r+1;
            }
            else
                return -1;
        }
            
        return 0;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        K=k;
        //dfs will return node distance from target
        dfs(root, target);
        return ans;
    }
}; 