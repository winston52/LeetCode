## LeetCode 876.Middle of the Linked List

### 自己的方法
#### 解决思路：    
* 首先得到链表的长度
* 再利用长度得到中间的结点
#### 注意事项：
* 当中间有两个结点时，输出第二个结点

### 大神的方法
#### 解决思路：
* 利用两个指针，快指针的步长为2，慢指针的步长为1，当快指针到达终点时，慢指针即指向中间的结点
#### 具体代码

```c++
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}
```
