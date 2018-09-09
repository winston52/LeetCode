## LeetCode 824.Goat Latin

### 方法1（常规方法）
#### 解决思路：    
* 利用两个栈，一个作为常规栈存储数据，另一个存储最小值的数据信息
#### 具体代码

```c++
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    /** initialize your data structure here. * /
    MinStack() {

    }

    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=s2.top())
            s2.push(x);
    }

    void pop() {
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```

### 方法2（进阶方法）
#### 解决思路：    
* 法巧妙地在每次入栈、出栈时进行简单的加减操作，达到可以直接获取最小元素的结果。
* 在入栈时，入的不是实际的元素值，而是与当前记录的最小值的差值，如果新入的更小，就将其设为最小值，此时就保证了随时可以获取最小值。
* 出栈时，要修改最小值。获取栈顶元素时，因为栈中记录的并不是原始值，所以要与记录的最小值进行操作来还原。
#### 注意事项
* 差值有可能超过int型的范围，因此要将计算过程中的数据类型设置为long型，具体返回时要先转换成int型再返回。
#### 具体代码
```c++
class MinStack {
public:
    stack<long> dif;
    long min;
    /** initialize your data structure here. * /
    MinStack() {

    }

    void push(int x) {
        if(dif.empty()){
            dif.push(0L);
            min = x;
        }else{
            dif.push(x-min);
            if(x<min)
                min = x;
        }
    }

    void pop() {
        if(dif.empty())
            return;
        else{
            long pop = dif.top();
            dif.pop();
            if(pop<0)
                min = min - pop;
        }
    }

    int top() {
        long top = dif.top();
        if(top<0)
            return (int)min;
        else
            return (int)min+top;
    }

    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 ```
