## LeetCode 232.Implement Queue using Stacks

#### 解决思路：    
* 利用两个队列，实现栈的功能
#### 参考网页
* [LeetCode 225: Implement Stack using Queues](https://blog.csdn.net/sunao2002002/article/details/46482673)

#### 具体代码

```c++
class MyStack {
    queue<int> q1,q2;
public:
    /** Initialize your data structure here. * /
    MyStack() {

    }

    /** Push element x onto stack. * /
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }            
        else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }   
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()){
            int x = q2.front();
            q2.pop();
            return x;
        }
        else{
            int x = q1.front();
            q1.pop();
            return x;
        }
    }

    /** Get the top element. */
    int top() {
        if(q1.empty())
            return q2.front();
        else
            return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
```
