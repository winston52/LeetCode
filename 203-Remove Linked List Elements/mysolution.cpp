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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;
        cur->next = head;
        while(cur){
            while(cur->next && cur->next->val == val){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};