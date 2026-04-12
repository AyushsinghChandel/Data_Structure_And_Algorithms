class MinStack {
public:
stack<int> mainStack;
stack<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }
        else{
            int minimum = min(val, minStack.top());
            minStack.push(minimum);
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
