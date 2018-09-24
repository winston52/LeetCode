## LeetCode 824.Goat Latin

### 递归1
#### 解决思路：    
* 从顶端往下递归
#### 具体代码
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;       
        std::swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

### 递归2
#### 解决思路
* 从底端往上递归
#### 具体代码
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(root->left)
            root->left = invertTree(root->left);
        if(root->right)
            root->right = invertTree(root->right);
        std::swap(root->left,root->right);
        return root;
    }
};
```

### 非递归1
#### 解决思路
* 利用堆栈实现树的反转
#### 具体代码
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* p = stk.top();
            stk.pop();
            if(p){
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left,p->right);
            }
        }
        return root;
    }
};
```

### 非递归2
#### 解决思路
* 利用队列实现树的反转
#### 具体代码
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> que;
        que.push(root);

        while(que.size() > 0){
            TreeNode* pFrontNode = que.front();
            que.pop();
            if(pFrontNode){
                que.push(pFrontNode->left);
                que.push(pFrontNode->right);
                std::swap(pFrontNode->left,pFrontNode->right);
            }
        }
        return root;
    }
};
```
