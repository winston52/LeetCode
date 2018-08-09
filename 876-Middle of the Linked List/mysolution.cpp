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
    ListNode* middleNode(ListNode* head) {
        ListNode *p=head,*q=head;
        int length=1;
        while(p){
            p=p->next;
            length++;
        }
        int j=1;
        while(q!=NULL&&j<(length+1)/2){
            q=q->next;
            j++;
        }
        return q;
    }
};