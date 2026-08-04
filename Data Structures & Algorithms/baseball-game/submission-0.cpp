class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> baseball;
        for (string &ops : operations) {
            if (ops == "+") {
                int top = baseball.top(); baseball.pop();
                int newtop = top + baseball.top();
                baseball.push(top);
                baseball.push(newtop);
            }
            else if (ops == "D") {
                baseball.push(2 * baseball.top());
            }
            else if (ops == "C") {
                baseball.pop();
            }
            else {
                baseball.push(stoi(ops));
            }
        } // <-- for loop ends HERE, before summing

        int sum = 0;
        while (!baseball.empty()) {
            sum += baseball.top();   // += not =
            baseball.pop();
        }
        return sum;
    }
};