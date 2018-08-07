## LeetCode 788.Rotated Digits

### ☆题意理解
#### 数字X旋转之后要和原先不同，因此在判断时要考虑如下两点
* ##### 首先当数字中包含3、4、7时，肯定不满足条件
* ##### 然后至少要包括2、5、6、9的其中一位，才能保证旋转之后的数字和原来不相同
### 自己的方法
#### 解决思路：    
* 首先遍历所有的数字，编写子函数判断该数字是否满足条件
* 在充分理解题意的基础上，编写子函数
#### 注意事项：
* 在编写子函数时，若没有考虑第二点，则所得结果会偏大（满足条件的数字变多，例如100）
### 方法的改进
#### 改进思想
* 可以增加判断首个数字是否为3、4、7的子函数，例如当`i=300`时，则直接返回99，使得下一次判断的`i`值为400，同理可得当`i=3000`时，直接返回999，使得下一次判断的i值为4000，因此能够提高效率。

#### 具体代码

``` Cpp
class Solution {
public:
    int judge(int k){
        int flag=0;
        if(k==1||k==8||k==10)
            return 0;
        while(k){
            if(k%10==3||k%10==4||k%10==7)
                return 0;
            if(k%10==2||k%10==5||k%10==6||k%10==9)
                flag = 1;
            k=k/10;
        }
        return flag;
    }

    int incrementIFNeeded(int i){
        int inc=1;
        while(i>=10){
            inc *=10;
            i=i/10;
        }
        if(i==3||i==4||i==7){
            return inc-1;
        }
        else
            return 0;
    }

    int rotatedDigits(int N) {
        int res=0;
        for(int i=1;i<=N;i++){
            if(judge(i))
                res++;
            i+=incrementIFNeeded(i);
        }
        return res;
    }
};
```
