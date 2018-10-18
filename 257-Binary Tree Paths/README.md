## LeetCode 257.Binary Tree Paths

### 解法1
#### 解决思路：    
* 深度优先遍历，递归解决问题
#### 具体代码：
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> resultPaths;
        if(root == NULL)
            return resultPaths;

        getTreePath(root,resultPaths,to_string(root->val));

        return resultPaths;
    }
private:
    void getTreePath(TreeNode* root,vector<string> &resultPaths,string singlePath){
        if(root->left == NULL && root->right == NULL){
            resultPaths.push_back(singlePath);
            return;
        }
        if(root->left != NULL){
            getTreePath(root->left,resultPaths,singlePath+"->"+to_string(root->left->val));
        }
        if(root->right != NULL){
            getTreePath(root->right,resultPaths,singlePath+"->"+to_string(root->right->val));
        }
    }
};
```

### 解法2
#### 解决思路：
* 利用堆栈，迭代解决问题
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> resultPaths;
        if(root == NULL)
            return resultPaths;

        stack<TreeNode*> nodeStack;
        stack<string> pathStack;
        nodeStack.push(root);
        pathStack.push(to_string(root->val));

        while(!nodeStack.empty()){
            TreeNode* topNode = nodeStack.top();
            nodeStack.pop();
            string singlePath = pathStack.top();
            pathStack.pop();

            if(topNode->left == NULL && topNode->right == NULL){
                resultPaths.push_back(singlePath);
                continue;
            }

            if(topNode->right != NULL){
                nodeStack.push(topNode->right);
                pathStack.push(singlePath+"->"+to_string(topNode->right->val));
            }

            if(topNode->left != NULL){
                nodeStack.push(topNode->left);
                pathStack.push(singlePath+"->"+to_string(topNode->left->val));
            }

        }
        return resultPaths;
    }
};
```
