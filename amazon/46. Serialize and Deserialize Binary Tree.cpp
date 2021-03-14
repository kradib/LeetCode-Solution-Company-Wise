//297. Serialize and Deserialize Binary Tree
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null ";
        string cur=to_string(root->val)+" ";
        cur+=serialize(root->left);
        cur+=serialize(root->right);
        return cur;
    }
    
    TreeNode* deserailizeRecur(queue<string> &temp){
        string first=temp.front();
        temp.pop();
        if(first=="null"){
            return NULL;
        }
        
        int value=stoi(first);
        TreeNode* root=new TreeNode(value);
        root->left=deserailizeRecur(temp);
        root->right=deserailizeRecur(temp);
        
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //cout<<data<<endl;
        stringstream ss(data);
        string temp;
        queue<string> nodes;
        while(ss>>temp){
            nodes.push(temp);
        }
        
        return deserailizeRecur(nodes);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));