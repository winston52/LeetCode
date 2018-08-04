## LeetCode 824.Goat Latin

### 自己的方法
#### 解决思路：    
* 利用空格，首先得到这句话中的每个单词	
* 再判断元音开头的单词，并对每个单词进行后期处理	
#### 注意事项：
* 由于最后一个单词后没有空格，本方案采用下标序号来判断是否为最后一个单词

### 大神的方法
#### 解决思路：
* 利用C++中stringstream去除空格，进而得到这句话中的每个单词
* 利用C++中string类的成员函数find/find_first_of来判断首字母是否为元音字母
#### 涉及的知识点：
[C++中stringstream的使用方法和样例](https://blog.csdn.net/sophia1224/article/details/53054698)
[string类成员函数find/find_first_of用法详解](https://blog.csdn.net/iot_change/article/details/8496977)