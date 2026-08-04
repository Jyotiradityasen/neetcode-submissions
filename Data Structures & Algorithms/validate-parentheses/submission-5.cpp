class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> my_stack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                my_stack.push(c);
            } else if (c == ')' && !my_stack.empty() && my_stack.top() == '(') {
                my_stack.pop();
            } else if (c == '}' && !my_stack.empty() && my_stack.top() == '{') {
                my_stack.pop();
            } else if (c == ']' && !my_stack.empty() && my_stack.top() == '[') {
                my_stack.pop();
            } else {
                return false;
            }
        }

        if (my_stack.size() == 0) {
            return true;
        }

        return false;
    }
};