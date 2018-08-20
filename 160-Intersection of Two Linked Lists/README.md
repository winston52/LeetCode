## LeetCode 160.Intersection of Two Linked Lists

### 方法一
#### 解决思路：    
* 首先获得两个链表的长度，并把较长的链表前一部分截断
* 再同时向后遍历两个链表直到找到相同的部分
#### 特点：
* 直接了当，易于理解

### 方法二
#### 解决思路：
* 利用链表无环的限定条件，当同时使用两个指针分别跑完两个链表
* 链表总会在交叉点处相遇
#### 特点
* 算法简洁巧妙
#### 参考博客：
* [LeetCode 160 Intersection of Two Linked Lists（链表相交）（Linked List）（*）](https://blog.csdn.net/NoMasp/article/details/50572819)
* [leetcode题解-160. Intersection of Two Linked Lists](https://blog.csdn.net/liuchonge/article/details/73556045)
#### 具体代码

* solution1
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);
        if(lenA>lenB){
            while(lenA!=lenB){
                lenA--;
                headA = headA->next;
            }
        }else{
            while(lenA!=lenB){
                lenB--;
                headB = headB->next;
            }
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;        
    }
public:
    int len(ListNode *head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
};
```

* solution2
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;        
        ListNode* a = headA;
        ListNode* b = headB;        
        while(a != b){
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};
```
