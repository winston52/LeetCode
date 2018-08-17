## LeetCode 234.Palindrome Linked List

#### 解决思路：    
* 首先找到链表的中间节点
* 再将后半部分链表反转
* 最后两部分链表同时遍历

#### 此题争议：
* [Reversing a list is not considered "O(1) space"](https://leetcode.com/problems/palindrome-linked-list/discuss/64493/Reversing-a-list-is-not-considered-%22O(1)-space%22l)

##### 争议理解
* 对于空间复杂度的常见误解是只考虑程序中使用了多大的内存空间，却并没有考虑输入
* 空间复杂度计算的重要前提是**输入只读**，因此在本题中，不允许通过反转链表的方式将输入改变
* 定义程序空间复杂度的另一方式是简单地观察程序要写入多少空间，由于反转链表需要写入`O(n)`的内存空间，因此对于反转链表的算法，其空间复杂度是`O(n)`而非`O(1)`

* ##### 要以`O(1)`的空间复杂度解决问题，理论上需要满足如下两点要求
* 程序计算时相当于一个有限自动机或者正则表达式检查程序（待理解）
* 根据Pumpling引理，回文字符串不能构成常规字符串
