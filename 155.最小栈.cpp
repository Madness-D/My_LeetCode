/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    //栈，先进后出
    //辅助栈，额外一个栈存储对应的最小值
    //空间复杂度蛮高的哦
    stack<int> x_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);

    }
    
    void push(int val) {
        x_stack.push(val);
        // if(val<min_stack.top()){
        //     min_stack.push(val);
        // }else{
        //     min_stack.push(min_stack.top());
        // }
        min_stack.push(min(val,min_stack.top()));

    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();

    }
    
    int getMin() {
        return min_stack.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

