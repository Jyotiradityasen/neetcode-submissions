class Solution {
public:
    bool isValid(string s) {
        stack <char> stacks;
        unordered_map <char,char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char c : s)
        {
            if(mp.count(c))
            {
                if(!stacks.empty() && stacks.top() == mp[c])
                {
                    stacks.pop();
                }
                else{
                    return false;
                }
            }
            else
            {
              stacks.push(c);
            }
        }
        return stacks.empty();

    }
};
