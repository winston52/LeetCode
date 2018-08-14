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
    void deleteNode(ListNode* node) {
        // 方法一        
        // *node = *node->next;
        
        // 方法二
        auto next = node->next;
        *node = *next;
        delete next;
    }
};