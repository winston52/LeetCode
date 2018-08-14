## LeetCode 21.Merge Two Sorted Lists

#### 解决思路：    
* 为了避免头节点的分类讨论，可以添加假的头结点
* 利用分别指向原来两个链表的指针，将其中比较小的节点添加到新的链表中
* 当其中一个链表已经遍历结束时，再继续将另一个链表的剩余部分进行拼接

### 递归的解决方法
#### 具体代码

```c++
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
```
