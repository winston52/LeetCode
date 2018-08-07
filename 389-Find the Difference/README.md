## LeetCode 389.Find the Difference

### 自己的方法
#### 解决思路：    
* 利用string类的方法特性
* 先用find方法找到每个字母的位置，再用erase方法将找到的字母去掉

### 大神的方法
#### 解决思路：
* 先后两次利用异或，最后得到的即为剩下的字母
#### 具体代码

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
```
