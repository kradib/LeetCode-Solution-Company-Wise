//138. Copy List with Random Pointer
//https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    map<Node*,Node*> mymap;
    
    
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        if(mymap.find(head)!=mymap.end())
            return mymap[head];
        
        Node* node= new Node(head->val,NULL,NULL);
        mymap[head]=node;
        
        node->next=copyRandomList(head->next);
        node->random=copyRandomList(head->random);
        
        return node;
        
        
    }
};