## LeetCode 20.Valid Parentheses

### 自己的方法
#### 解决思路：    
* 常规处理，遇见任意括号的前半部分入栈处理
* 遇见括号的后半部分与栈顶元素比较
#### 注意事项：
* 注意判断栈是否为空栈

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> tem;
        for(int i=0;i<s.length();i++){
            switch (s[i]){
                case '[':
                case '{':
                case '(':
                    tem.push(s[i]);
                    break;
                case ']':
                    if(tem.empty()||tem.top()!='['){
                        return false;
                    }else{
                        tem.pop();
                        break;
                    }
                case '}':
                    if(tem.empty()||tem.top()!='{'){
                        return false;
                    }else{
                        tem.pop();
                        break;
                    }
                case ')':
                    if(tem.empty()||tem.top()!='('){
                        return false;
                    }else{
                        tem.pop();
                        break;
                    }
            }
        }
        return tem.empty();
    }
};
```

### 方法的改进
#### 改进思路：
* 当遇见括号的前半部分时，则将括号的后半部分入栈处理
* 遇见括号的后半部分则与栈顶元素比较
#### 改进优势：
* 能够将原有的代码简洁化，对于括号的后半部分统一处理
#### 具体代码

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> tem;
        for(char& c:s){
            if(c == '(')
                tem.push(')');
            else if(c == '[')
                tem.push(']');
            else if(c == '{')
                tem.push('}');
            else if(tem.empty()||tem.top() != c)
                return false;
            else
                tem.pop();
        }
        return tem.empty();
    }
};
```
