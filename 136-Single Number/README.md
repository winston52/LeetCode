## LeetCode136.Single Number

### 解决方法
#### 解决思路：    
* 利用异或的思想，最终留下的一定是落单的数
#### 具体代码
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tem = 0;

        for(int i=0;i<nums.size();i++)
            tem = tem ^ nums[i];

        return tem;
    }
};
```
