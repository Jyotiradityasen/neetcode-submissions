class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> baseball;
        int res = 0;
        for (string &ops : operations)
        {
            if (ops == "+")
            {
                int top = baseball.top(); baseball.pop();
                int nexttop = top + baseball.top();
                baseball.push(top);
                baseball.push(nexttop);
                res += nexttop;
            }
            else if (ops == "D")
            {
                baseball.push(baseball.top() * 2);
                res += baseball.top();
            }
            else if (ops == "C")
            {
                res -= baseball.top();
                baseball.pop();
            }
            else
            {
                baseball.push(stoi(ops));
                res += baseball.top();
            }
        }
        return res;
    }
};