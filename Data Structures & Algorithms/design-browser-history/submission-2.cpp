class BrowserHistory {
    struct ListNode
    {
        string val;
        ListNode *prev;
        ListNode *next;
        ListNode(string val, ListNode *prev = nullptr, ListNode *next = nullptr)
            : val(val), prev(prev), next(next)
        {
        }   // FIX: no semicolon after a constructor body — that's not a statement
    };      // FIX: missing semicolon here. A struct/class definition MUST end with
            // ";" after the closing brace. Without it, the compiler thinks
            // "ListNode* cur;" is still part of the struct declaration.

    ListNode* cur;

public:
    BrowserHistory(string homepage) {
        cur = new ListNode(homepage);
    }
    
    void visit(string url) {
        cur->next = new ListNode(url, cur, nullptr);  
        // FIX: missing semicolon at the end of this line
        cur = cur->next;
    }
    
    string back(int steps) {
        while (steps != 0 && cur->prev != nullptr)
        {
            steps--;        // FIX: was "step--" — undeclared variable, must be "steps"
            cur = cur->prev;
        }
        return cur->val;
    }               // FIX: this closing brace for back() was missing entirely.
                    // Your return statement was left dangling outside any function
                    // body, and forward()'s definition started before back() had
                    // even closed — that's a cascading syntax error.
    
    string forward(int steps) {
        while (cur->next != nullptr && steps > 0) {
            cur = cur->next;
            steps--;
        }
        return cur->val;
    }
};