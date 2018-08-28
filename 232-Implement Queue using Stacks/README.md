## LeetCode 232.Implement Queue using Stacks

#### 解决思路：    
* 利用两个栈，实现队列的功能

#### 具体代码

```c++
class MyQueue {
    stack<int> input,output;
public:
    /** Initialize your data structure here. * /
    MyQueue() {

    }

    /** Push element x to the back of queue. * /
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(output.empty())
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int x = output.top();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if(output.empty())
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
```
