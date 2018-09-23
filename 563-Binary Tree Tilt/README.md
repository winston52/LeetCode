## LeetCode 563.Binary Tree Tilt

#### 解决思路：    
* 后序递归遍历所有结点，分别得到所有子树的**所有结点数值**之和
* 遍历的同时将求解左右子树的差的绝对值，并累加（变量的作用域大于遍历函数）

#### 具体代码

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int result = 0;
public:
    int findTilt(TreeNode* root) {
        postOrder(root);
        return result;
    }
private:
   int postOrder(TreeNode * root) {
       if(root == NULL)
           return 0;
       int lSum = postOrder(root->left);
       int rSum = postOrder(root->right);
       result += abs(lSum-rSum);
       return lSum+rSum+root->val;
   }
};
```
