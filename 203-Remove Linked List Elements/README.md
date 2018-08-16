## LeetCode 203.Remove Linked List Elements

### 自己的方法
#### 解决思路：    
* 由于节点删除时需要知道前序节点，而首节点也可能面临被删除的情况，因此创建一个虚节点
* 再遍历链表，判断结点的值是否等于相应的值
#### 注意事项：
* 将虚节点的指针域作为函数的返回值

### 递归的解决方法
#### 具体代码
```c++
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
        if(head == NULL)
            return NULL;
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next:head;
    }
};
```
#### 理解
* 从后往前推导，便于理解，先遍历到尾节点，再根据值决定是否将链表的节点添加
```
It basically goes down to the last null node, and rebuilds the linked list, by adding only the nodes which are not equal to val to this null, so it goes from
null ;
[5->null] //when head is 6 it doesnt add anything to head
[4-->5-->null]
[3-->4-->5-->null]
[2-->3-->4-->5-->null]
[1-->2-->3-->4-->5-->null]
```
