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
    bool isPalindrome(ListNode* head) {
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
       
        ListNode *tail;
        tail = reserveList(slow);
        
        while(tail!=NULL){
            if(head->val!=tail->val){
                return false;
            }
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
    
private:    
    ListNode* reserveList(ListNode* head){
        ListNode *pre = NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};