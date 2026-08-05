class MinStack {
public:
    stack <int> stacks;
    MinStack() {

        
    }
    
    void push(int val) {

        stacks.push(val);
    }
    
    void pop() {
        stacks.pop();
    }
    
    int top() {
        return stacks.top();
    }
    
    int getMin() {
        int mini=stacks.top();
        stack <int> temp;
        while(!stacks.empty())
        {
            mini=min(mini,stacks.top());
            temp.push(stacks.top());
            stacks.pop();
        }
        while(!temp.empty())
         {
            stacks.push(temp.top());
            temp.pop();
        }
    return mini;
    }
};
