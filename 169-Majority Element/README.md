## LeetCode 169.Majority Element

### 方法1
#### 解决思路：
* 先排序，返回的中间值肯定是出现次数大于数组长度一半的元素
#### 涉及的知识点：
* [C++ 排序函数 sort(),qsort()的用法](https://blog.csdn.net/zzzmmmkkk/article/details/4266888)
#### 具体代码
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
```
### 方法2
#### 解决思路：
* 将候选众数存在变量candidate中，由于众数总是存在，因此每出现一对不一样的就可以忽视这一对。再利用计数来表示，来一个数字和candidate相同则count++，否则count--，如果count为零，则candidate就是下一个数，最终遍历结束后candidate中存放的即为众数。
#### 具体代码
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nTimes = 0;
        int candidate;
        for(int i=0;i<nums.size();i++){
            if(nTimes == 0){
                candidate = nums[i];
                nTimes++;
            }
            else{
                if(candidate == nums[i])
                    nTimes++;
                else
                    nTimes--;
            }
        }
        return candidate;
    }
};
```
#### 参考网址
* [leetcode[169] Majority Element](https://www.cnblogs.com/higerzhang/p/4181421.html)

### 方法3
#### 解决思路
* int类型是32位，众数一定存在，则每一位考虑，对于每一位1或者0多的肯定是属于众数的，这样就可以求解众数。
#### 涉及的知识点
* [
memset()函数及其作用](https://blog.csdn.net/qq_27522735/article/details/53374765)
#### 具体代码
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int bitCnt[32];
        int res = 0;
        memset(bitCnt,0,sizeof(bitCnt));

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i] & 1<<j)
                    bitCnt[j]++;
            }
        }

        for(int j=0;j<32;j++){
            if(bitCnt[j]>nums.size()/2)
                res += (int)pow(2,j);
        }

        return res;
    }
};
```
