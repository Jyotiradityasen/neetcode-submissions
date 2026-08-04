class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> stacks;
        int res=0;
        for( string &ops : operations)
        {
            if(ops == "+")
            {
                int top = stacks.top();stacks.pop();
                int newtop=stacks.top()+top;
                stacks.push(top);
                stacks.push(newtop);
                res+=newtop;
            }
            else if(ops == "D")
            {
                stacks.push(stacks.top()*2);
                res+= stacks.top();
            }
            else if(ops == "C")
            {
                res-=stacks.top();
                stacks.pop();
            }
            else
            {
                stacks.push(stoi(ops));
                res += stacks.top();
            }
        
        }
        return res;
        
    }
};