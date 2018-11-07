## LeetCode 649.Dota2 Senate

### 方法1
#### 解决思路：
* 利用两个队列实现，不断返回字母R和D的下标到队列中，并不断比较下标值
* 下标值+n即表示进入下一轮循环遍历
#### 涉及的知识点：
* C++队列的操作
#### 具体代码
```c++
class Solution {
public:
    string predictPartyVictory(string senate) {
       int n = senate.length();
        queue<int> qR,qD;
        for(int i=0;i<n;i++){
            if(senate[i] == 'R')
                qR.push(i);
            else
                qD.push(i);
        }
        while(!qR.empty() && !qD.empty()){
            int rIndex = qR.front();
            int dIndex = qD.front();
            qR.pop();
            qD.pop();
            if(rIndex < dIndex)
                qR.push(rIndex + n);
            else
                qD.push(dIndex + n);            
        }
        return qR.size() > qD.size() ? "Radiant" : "Dire";
    }
};
```
