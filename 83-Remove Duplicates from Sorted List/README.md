## LeetCode 824.Goat Latin

### 自己的方法
#### 解决思路：    
* 利用两个指针，一个指向当前不重复的最后一个元素(前指针)，一个进行依次扫描(后指针)
* 当后指针遇到不重复的元素时则更新前指针，否则就将前指针指向后指针所指向元素的下一个元素
#### 参考博客
* [Remove Duplicates from Sorted List -- LeetCode](https://blog.csdn.net/linhuanmars/article/details/24354291)

### 大神解法
#### 解决思路
* 合理设计`while`循环层数及条件
* 若当前指针的下一个元素存在，且值与下一个元素相等时，再进行操作
#### 具体代码

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while(cur){
            while(cur->next && cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
```
