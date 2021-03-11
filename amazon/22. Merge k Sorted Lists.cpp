//23. Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:                                                                                                        
    
    bool allnotnull(vector<ListNode*>& lists){
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                return true;
        return false;
    }
    
    int findmin(vector<ListNode*>& lists){
        
        int index=-1,minimum=INT_MAX;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL && lists[i]->val<minimum){
                //store=list[i];
                index=i;
                minimum=lists[i]->val;
            }
        }
        
        return index;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        ListNode* head,*store=NULL;
        int index=-1,minimum=INT_MAX;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL && lists[i]->val<minimum){
                store=lists[i];
                index=i;
                minimum=lists[i]->val;
            }
        }
        if(index==-1)
            return NULL;
        head=store;
        lists[index]=lists[index]->next;
        ListNode* result=head;
        
        
        while(allnotnull(lists)){
            
            int q=findmin(lists);
            head->next=lists[q];
            head=head->next;
            lists[q]=lists[q]->next;
            
        }
        
        return result;
        
    }
};