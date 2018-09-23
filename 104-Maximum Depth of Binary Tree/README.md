## LeetCode 824.Goat Latin

#### 解决思路：    
* 二叉树的高度等于左右子树节点的高度的最大值+1

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
public:
    int maxDepth(TreeNode* root) {
        int HL,HR,MaxH;
        if(root){
            HL = maxDepth(root->left);
            HR = maxDepth(root->right);
            MaxH = HL>HR ? HL:HR;
            return MaxH+1;
        }
        else
            return 0;
    }
};
```
