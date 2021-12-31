/*
Two approaches
1. Using two queues(make either push costlier or pop costlier)
2. Using single queue{firstly push the lement ,and then take size-1 elements from queue and push them again}
*/

class MyStack {
public:
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int f;
        if(!q.empty()){
            f=q.front();
            q.pop();
            return f;
        }
        return NULL;
    }
    
    int top() {
        if(!q.empty()) return q.front();
        return NULL;
    }
    
    bool empty() {
        return q.empty();
    }
};
