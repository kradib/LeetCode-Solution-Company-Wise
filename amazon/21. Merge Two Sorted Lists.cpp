//21. Merge Two Sorted Lists
//https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoListsRecur(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* temphead;
        if(l1->val>l2->val){
            temphead=l2;
            temphead->next=mergeTwoListsRecur(l1, l2->next);
        }
        else{
            temphead=l1;
            temphead->next=mergeTwoListsRecur(l1->next, l2);
        }
            
        return temphead;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        head=mergeTwoListsRecur(l1,l2);
        return head;
    }
};