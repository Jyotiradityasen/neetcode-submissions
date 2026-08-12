class BrowserHistory {
public: 
    stack <string> bh,fh;
    BrowserHistory(string homepage) {
        bh.push(homepage);
    }
    
    void visit(string url) {
        bh.push(url);
        fh=stack<string>();
    }
    
    string back(int steps) {
        while (steps-- && bh.size() >1)
        {
            fh.push(bh.top());
            bh.pop();
        }
        return bh.top();
    }
    
    string forward(int steps) {
        while(steps-- && !fh.empty())
        {
            bh.push(fh.top());
            fh.pop();
        }
        return bh.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */