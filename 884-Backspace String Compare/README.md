## LeetCode 844.Backspace String Compare

### 方法一
#### 解决思路：    
* 利用栈进行处理
#### 注意事项：
* 此方法的时间复杂度为 $O(n)$ ，空间复杂度为 $O(n)$。
#### 具体代码
```c++
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return type(S)==type(T);
    }
private:
    string type(string str){
        string res;
        for(char c : str){
            if(c == '#'){
                if(!res.empty())
                    res.pop_back();
            }
            else
                res.push_back(c);
        }
        return res;
    }
};
```

### 方法二
#### 解决思路：
* 利用下标从尾部往前遍历，计算#号的数目，#号的数目即为可忽略的字母数量

#### 具体代码及注释
```c++
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
        while(i >= 0 || j >= 0){//外层循环，只要下标i和j存在大于0的时候，就进入内层循环
            while(i >= 0 && (S[i] == '#' || countA > 0)) S[i--] == '#' ? countA++ : countA--;
//只要i为正，且当前字符为#时或者前面的#号影响还未消失(count值不为0)时，循环不结束，直到判断到第一个不能被忽略的字母
//如ab#cd#，判断到第一个不能被忽略的字母为c，本次循环结束，后面还有可能继续判断
            while(j >= 0 && (T[j] == '#' || countB > 0)) T[j--] == '#' ? countB++ : countB--;
            if(i < 0 || j < 0) return i == j;  
//当一次判断之后，i和j出现小于零的值时，即#号的数目刚好等于被忽略的字母数目时，返回两个字符串下标值的比较结果
//如果有一个下标值为零而另一个下标值不为零，则说明有效字母的数目不一致，也不用继续考虑后面的字母，直接返回结果即可
            if(S[i--] != T[j--]) return false;
//当发现存在不能被忽略的字母，且字母不相等时，则直接返回false，不用继续考虑后面的字母
        }
        return true;
    }
};
```
